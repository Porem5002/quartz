/*
MIT License

Copyright (c) 2024-2025 Carlos Bandeira

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <gapil.h>

#include "../include/notify.h"
#include "../include/window.h"
#include "../include/input.h"

#include "internals/window.h"

#ifdef _WIN32

static LRESULT CALLBACK quartz_windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam);
static quartz_keycode quartz_windows_map_key(WPARAM virtual_key);

void quartz_window_create(quartz_window* window, int width, int height, const char* title)
{
    const char* class_name = "QUARTZ_WIN";
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = class_name;
    wc.lpfnWndProc = quartz_windows_window_callback; // Window callback function

    quartz_assert(RegisterClassA(&wc), "Failed on call to RegisterClassA during window creation");

    DWORD dwStyle = WS_OVERLAPPEDWINDOW;

    // Generate temporary window, dc and rc so that we can extract special OPenGL functions 
    {
        quartz_window window = {};
        window.wnd = CreateWindowExA(0, class_name, title, dwStyle, 100, 100, width, height, NULL, NULL, instance, &window);
        quartz_assert(window.wnd != NULL, "Failed to create dummy window for OpenGL setup!");

        window.dc = GetDC(window.wnd);
        quartz_assert(window.dc != NULL, "Failed to get DC!");

        PIXELFORMATDESCRIPTOR pfd = {};
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cAlphaBits = 8;
        pfd.cDepthBits = 24;

        int pixelFormat = ChoosePixelFormat(window.dc, &pfd);
        quartz_assert(pixelFormat != 0, "Failed to choose pixel format!");
        quartz_assert(SetPixelFormat(window.dc, pixelFormat, &pfd), "Failed to set pixel format!");

        // Create fake opengl rendering context
        window.rc = wglCreateContext(window.dc);
        quartz_assert(window.rc != NULL, "Failed to create opengl context!");
        quartz_assert(wglMakeCurrent(window.dc, window.rc) != 0, "Failed to make current!");

        gapil_load();

        quartz_window_destroy(&window);
    }

    RECT borderRect = {};
    AdjustWindowRectEx(&borderRect, dwStyle, 0, 0);

    width += (int)(borderRect.right - borderRect.left);
    height += (int)(borderRect.bottom - borderRect.top);

    *window = {};
    window->wnd = CreateWindowExA(0, class_name, title, dwStyle, 100, 100, width, height, NULL, NULL, instance, window);
    quartz_assert(window->wnd != NULL, "Failed to create dummy window for OpenGL setup!");

    window->dc = GetDC(window->wnd);
    quartz_assert(window->dc != NULL, "Failed to get DC!");

    const int pixelAttribs [] = {
        WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
        WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
        WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
        WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
        WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
        WGL_COLOR_BITS_ARB, 32,
        WGL_ALPHA_BITS_ARB, 8,
        WGL_DEPTH_BITS_ARB, 24,
        0
    };

    UINT numPixelFormats;
    int pixelFormat = 0;

    quartz_assert(wglChoosePixelFormatARB(window->dc, pixelAttribs, 0, 1, &pixelFormat, &numPixelFormats),
                  "Failed call to 'wglChoosePixelFormatARB'");

    PIXELFORMATDESCRIPTOR pfd = {};
    DescribePixelFormat(window->dc, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
    quartz_assert(SetPixelFormat(window->dc, pixelFormat, &pfd), "Failed to SetPixelFormat");

    const int contextAttribs [] = {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
        WGL_CONTEXT_MINOR_VERSION_ARB, 3,
        WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB,
        0
    };

    window->rc = wglCreateContextAttribsARB(window->dc, 0, contextAttribs);
    quartz_assert(window->rc != NULL, "Failed to create opengl context!");
    quartz_assert(wglMakeCurrent(window->dc, window->rc), "Failed to make current!");

    ShowWindow(window->wnd, SW_SHOW);
}

void quartz_window_update(quartz_window* window)
{
    MSG msg;

    window->resized = false;

    while(PeekMessageA(&msg, window->wnd, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg); // Sends message to the callback function of the window
    }
}

void quartz_window_swap_buffers(quartz_window* window)
{
    SwapBuffers(window->dc);
}

void quartz_window_sync_address(quartz_window* window)
{
    SetWindowLongPtr(window->wnd, GWLP_USERDATA, (LONG_PTR)window);
}

void quartz_window_destroy(quartz_window* window)
{
    wglMakeCurrent(window->dc, 0);
    wglDeleteContext(window->rc);
    ReleaseDC(window->wnd, window->dc);
    DestroyWindow(window->wnd);
}

static LRESULT CALLBACK quartz_windows_window_callback(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    quartz_window* window = (quartz_window*)GetWindowLongPtr(wnd, GWLP_USERDATA);

    LRESULT result = 0;

    switch (msg)
    {
        case WM_CREATE:
        {
            CREATESTRUCTA* creation_data = (CREATESTRUCTA*)lParam;
            quartz_window* window = (quartz_window*)creation_data->lpCreateParams;
            quartz_assert(window != nullptr, "Invalid window in window callback!");
            SetWindowLongPtr(wnd, GWLP_USERDATA, (LONG_PTR)window);

            RECT rect;
            GetClientRect(window->wnd, &rect);

            int width = (int)(rect.right - rect.left);
            int height = (int)(rect.bottom - rect.top);

            window->size = { width, height };
            window->running = true;
            break;
        }
        case WM_CLOSE:
        {
            quartz_assert(window != nullptr, "Invalid window in window callback!");
            window->running = false;
            break;
        }
        case WM_SIZE:
        {
            quartz_assert(window != nullptr, "Invalid window in window callback!");

            RECT rect;
            GetClientRect(window->wnd, &rect);

            int new_width = (int)(rect.right - rect.left);
            int new_height = (int)(rect.bottom - rect.top);

            window->size = { new_width, new_height };
            window->resized = true;
            break;
        }
        case WM_MOUSEMOVE:
        {
            quartz_assert(window != nullptr, "Invalid window in window callback!");

            POINT mouse_pos;
            GetCursorPos(&mouse_pos);
            ScreenToClient(window->wnd, &mouse_pos);
            
            int mouse_x = quartz_clamp((int)mouse_pos.x, 0, window->size.x);
            int mouse_y = quartz_clamp((int)mouse_pos.y, 0, window->size.y);

            window->mouse_pos.x = mouse_x;
            window->mouse_pos.y = window->size.y - mouse_y;
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
        case WM_XBUTTONDOWN:
        case WM_XBUTTONUP:
        {
            quartz_keycode key = GET_XBUTTON_WPARAM(wParam) == 1 ?
                QUARTZ_KEY_X1_MOUSE_BTN : QUARTZ_KEY_X2_MOUSE_BTN;
            quartz_register_key(key, msg == WM_XBUTTONUP);
            break;
        }
        case WM_KEYDOWN:
        case WM_KEYUP:
        {
            quartz_keycode key = quartz_windows_map_key(wParam);
            quartz_register_key(key, msg == WM_KEYUP);
            break;
        }
        default:
            result = DefWindowProcA(wnd, msg, wParam, lParam);
            break;
    }

    return result;
}

static quartz_keycode quartz_windows_map_key(WPARAM virtual_key)
{
    // Windows uses the ASCII codes of digits and letters to represent their respective keys,
    // since we do the same for ours, we can directly map them 
    if(virtual_key >= '0' && virtual_key <= '9') return (quartz_keycode)virtual_key;
    if(virtual_key >= 'A' && virtual_key <= 'Z') return (quartz_keycode)virtual_key;

    if(virtual_key >= VK_NUMPAD0 && virtual_key <= VK_NUMPAD9)
        return (quartz_keycode)(QUARTZ_KEY_NUMPAD_0 + (virtual_key - VK_NUMPAD0));

    if(virtual_key >= VK_F1 && virtual_key <= VK_F12)
        return (quartz_keycode)(QUARTZ_KEY_F1 + (virtual_key - VK_F1));

    switch(virtual_key)
    {
        case VK_BACK: return QUARTZ_KEY_BACK;
        case VK_RETURN: return QUARTZ_KEY_ENTER;

        case VK_ESCAPE: return QUARTZ_KEY_ESC;
        case VK_TAB: return QUARTZ_KEY_TAB;
        case VK_CAPITAL: return QUARTZ_KEY_CAPSLOCK;
        case VK_SHIFT: return QUARTZ_KEY_SHIFT;
        case VK_CONTROL: return QUARTZ_KEY_CTRL;
        case VK_MENU: return QUARTZ_KEY_ALT;
        case VK_SPACE: return QUARTZ_KEY_SPACE;

        case VK_UP:  return QUARTZ_KEY_ARROW_UP;
        case VK_DOWN: return QUARTZ_KEY_ARROW_DOWN;
        case VK_LEFT: return QUARTZ_KEY_ARROW_LEFT;
        case VK_RIGHT: return QUARTZ_KEY_ARROW_RIGHT;

        default: return QUARTZ_KEY_NONE;
    }

    quartz_fail("Unreachable");
}

#endif