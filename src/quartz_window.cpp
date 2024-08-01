#include "include/glload.hpp"
#include "include/quartz_common.hpp"
#include "include/quartz_window.hpp"
#include "include/quartz_input.hpp"

#ifdef _WIN32

static quartz_window* curr_active_window;

static LRESULT CALLBACK quartz_windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam);
static quartz_keycode quartz_windows_map_key(WPARAM virtual_key);

quartz_window quartz_window_create(int width, int height, const char* title)
{
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title; // This is not the title, but we use title as a unique identifier of the window
    wc.lpfnWndProc = quartz_windows_window_callback; // Window callback function

    QUARTZ_ASSERT(RegisterClassA(&wc), "Failed on call to RegisterClassA during window creation");

    DWORD dwStyle = WS_OVERLAPPEDWINDOW;

    // Generate temporary window, dc and rc so that we can extract special OPenGL functions 
    {
        quartz_window q_window = {};
        curr_active_window = &q_window;

        q_window.win_window = CreateWindowExA(0, title, // Unique identifier again
                                        title, dwStyle, 100, 100, width, height, NULL, NULL, instance, NULL);
        QUARTZ_ASSERT(q_window.win_window != NULL, "Failed to create dummy window for OpenGL setup!");

        q_window.win_dc = GetDC(q_window.win_window );
        QUARTZ_ASSERT(q_window.win_dc != NULL, "Failed to get DC!");

        PIXELFORMATDESCRIPTOR pfd = {};
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cAlphaBits = 8;
        pfd.cDepthBits = 24;

        int pixelFormat = ChoosePixelFormat(q_window.win_dc, &pfd);
        QUARTZ_ASSERT(pixelFormat != 0, "Failed to choose pixel format!");
        QUARTZ_ASSERT(SetPixelFormat(q_window.win_dc, pixelFormat, &pfd), "Failed to set pixel format!");

        // Create fake opengl rendering context
        q_window.win_rc = wglCreateContext(q_window.win_dc);
        QUARTZ_ASSERT(q_window.win_rc != NULL, "Failed to create opengl context!");
        QUARTZ_ASSERT(wglMakeCurrent(q_window.win_dc, q_window.win_rc) != 0, "Failed to make current!");

        load_wgl_functions();

        // Cleanup temporary contexts
        wglMakeCurrent(q_window.win_dc, 0);
        wglDeleteContext(q_window.win_rc);
        ReleaseDC(q_window.win_window, q_window.win_dc);
        DestroyWindow(q_window.win_window);
    }

    quartz_window window = {};
    curr_active_window = &window;

    RECT borderRect = {};
    AdjustWindowRectEx(&borderRect, dwStyle, 0, 0);

    width += (int)(borderRect.right - borderRect.left);
    height += (int)(borderRect.bottom - borderRect.top);

    window.win_window = CreateWindowExA(0, title, // Unique identifier again
                                    title, dwStyle, 100, 100, width, height, NULL, NULL, instance, NULL);
    QUARTZ_ASSERT(window.win_window != NULL, "Failed to create dummy window for OpenGL setup!");

    window.win_dc = GetDC(window.win_window);
    QUARTZ_ASSERT(window.win_dc != NULL, "Failed to get DC!");

    const int pixelAttribs [] = {
        WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
        WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
        WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
        WGL_SWAP_METHOD_ARB, WGL_SWAP_COPY_ARB,
        WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
        WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
        WGL_COLOR_BITS_ARB, 32,
        WGL_ALPHA_BITS_ARB, 8,
        WGL_DEPTH_BITS_ARB, 24,
        0
    };

    UINT numPixelFormats;
    int pixelFormat = 0;

    QUARTZ_ASSERT(wglChoosePixelFormatARB(window.win_dc, pixelAttribs, 0, 1, &pixelFormat, &numPixelFormats),
                  "Failed call to 'wglChoosePixelFormatARB'");

    PIXELFORMATDESCRIPTOR pfd = {};
    DescribePixelFormat(window.win_dc, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

    QUARTZ_ASSERT(SetPixelFormat(window.win_dc, pixelFormat, &pfd), "Failed to SetPixelFormat");

    const int contextAttribs [] = {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
        WGL_CONTEXT_MINOR_VERSION_ARB, 3,
        WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB,
        0
    };

    window.win_rc = wglCreateContextAttribsARB(window.win_dc, 0, contextAttribs);
    QUARTZ_ASSERT(window.win_rc != NULL, "Failed to create opengl context!");
    QUARTZ_ASSERT(wglMakeCurrent(window.win_dc, window.win_rc), "Failed to make current!");

    ShowWindow(window.win_window, SW_SHOW);

    curr_active_window = nullptr;
    return window;
}

void quartz_window_update(quartz_window* window)
{
    MSG msg;

    curr_active_window = window;
    curr_active_window->resized = false;

    while(PeekMessageA(&msg, window->win_window, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg); // Sends message to the callback function of the window
    }

    curr_active_window = nullptr;
}

void quartz_window_swap_buffers(quartz_window* window)
{
    SwapBuffers(window->win_dc);
}

static LRESULT CALLBACK quartz_windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
    QUARTZ_ASSERT(curr_active_window != nullptr, "Invalid window in window callback!");

    LRESULT result = 0;

    switch (msg)
    {
        case WM_CREATE:
        {
            RECT rect;
            GetClientRect(window, &rect);

            auto width = (unsigned)(rect.right - rect.left);
            auto height = (unsigned)(rect.bottom - rect.top);

            curr_active_window->size = { width, height };
            curr_active_window->running = true;
            break;
        }
        case WM_CLOSE:
            curr_active_window->running = false;
            break;
        case WM_SIZE:
        {
            RECT rect;
            GetClientRect(window, &rect);

            auto new_width = (unsigned)(rect.right - rect.left);
            auto new_height = (unsigned)(rect.bottom - rect.top);

            curr_active_window->size = { new_width, new_height };
            curr_active_window->resized = true;

            break;
        }
        case WM_MOUSEMOVE:
        {
            POINT mouse_pos;
            GetCursorPos(&mouse_pos);
            ScreenToClient(curr_active_window->win_window, &mouse_pos);
            
            auto mouse_x = (unsigned)quartz_clamp((int64_t)mouse_pos.x, 0i64, (int64_t)curr_active_window->size.x);
            auto mouse_y = (unsigned)quartz_clamp((int64_t)mouse_pos.y, 0i64, (int64_t)curr_active_window->size.y);

            curr_active_window->mouse_pos.x = mouse_x;
            curr_active_window->mouse_pos.y = curr_active_window->size.y - mouse_y;
            break;
        }
        case WM_LBUTTONDOWN:
        case WM_LBUTTONUP:
            quartz_register_key(QUARTZ_KEY_L_MOUSE_BTN, msg == WM_LBUTTONUP);
            break;
        case WM_RBUTTONDOWN:
        case WM_RBUTTONUP:
            quartz_register_key(QUARTZ_KEY_R_MOUSE_BTN, msg == WM_RBUTTONUP);
            break;
        case WM_MBUTTONDOWN:
        case WM_MBUTTONUP:
            quartz_register_key(QUARTZ_KEY_M_MOUSE_BTN, msg == WM_MBUTTONUP);
            break;
        case WM_KEYDOWN:
        case WM_KEYUP:
        {
            quartz_keycode key = quartz_windows_map_key(wParam);
            quartz_register_key(key, msg == WM_KEYUP);
            break;
        }
        default:
            result = DefWindowProcA(window, msg, wParam, lParam);
            break;
    }

    return result;
}

static quartz_keycode quartz_windows_map_key(WPARAM virtual_key)
{
    if(virtual_key >= 0x30 && virtual_key <= 0x39)
        return (quartz_keycode)(QUARTZ_KEY_0 + (virtual_key - 0x30));

    if(virtual_key >= 0x41 && virtual_key <= 0x5A)
        return (quartz_keycode)(QUARTZ_KEY_A + (virtual_key - 0x41));

    if(virtual_key >= VK_NUMPAD0 && virtual_key <= VK_NUMPAD9)
        return (quartz_keycode)(QUARTZ_KEY_NUMPAD_0 + (virtual_key - VK_NUMPAD0));

    if(virtual_key == VK_BACK) return QUARTZ_KEY_BACK;
    if(virtual_key == VK_TAB) return QUARTZ_KEY_TAB;
    if(virtual_key == VK_SPACE) return QUARTZ_KEY_SPACE;

    return QUARTZ_KEY_NONE;
}

#endif