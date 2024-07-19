#include "include/quartz.hpp"
#include "include/glload.hpp"

#include <wglext.h>

quartz_context quartz_implicit_context;

#ifdef _WIN32

static LRESULT CALLBACK quartz_windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam);

void quartz_start(int width, int height, const char* title)
{
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title; // This is not the title, but we use title as a unique identifier of the window
    wc.lpfnWndProc = quartz_windows_window_callback; // Window callback function

    QUARTZ_ASSERT(RegisterClassA(&wc), "Failed on call to RegisterClassA during window creation");

    int dwStyle = WS_OVERLAPPEDWINDOW;
    
    PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
    PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;

    // Generate temporary window, dc and rc so that we can extract special OPenGL functions 
    {
        HWND tmp_window = CreateWindowExA(0, title, // Unique identifier again
                                        title, dwStyle, 100, 100, width, height, NULL, NULL, instance, NULL);
        QUARTZ_ASSERT(tmp_window != NULL, "Failed to create dummy window for OpenGL setup!");

        HDC tmp_dc = GetDC(tmp_window);
        QUARTZ_ASSERT(tmp_dc != NULL, "Failed to get DC!");

        PIXELFORMATDESCRIPTOR pfd = {};
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cAlphaBits = 8;
        pfd.cDepthBits = 24;

        int pixelFormat = ChoosePixelFormat(tmp_dc, &pfd);
        QUARTZ_ASSERT(pixelFormat != 0, "Failed to choose pixel format!");
        QUARTZ_ASSERT(SetPixelFormat(tmp_dc, pixelFormat, &pfd), "Failed to set pixel format!");

        // Create fake opengl rendering context
        HGLRC tmp_rc = wglCreateContext(tmp_dc);
        QUARTZ_ASSERT(tmp_rc != NULL, "Failed to create opengl context!");
        QUARTZ_ASSERT(wglMakeCurrent(tmp_dc, tmp_rc) != 0, "Failed to make current!");

        wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)load_gl_function_by_name("wglChoosePixelFormatARB");
        wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)load_gl_function_by_name("wglCreateContextAttribsARB");

        // Cleanup temporary contexts
        wglMakeCurrent(tmp_dc, 0);
        wglDeleteContext(tmp_rc);
        ReleaseDC(tmp_window, tmp_dc);
        DestroyWindow(tmp_window);
    }
    
    RECT borderRect = {};
    AdjustWindowRectEx(&borderRect, dwStyle, 0, 0);

    width += borderRect.right - borderRect.left;
    height += borderRect.bottom - borderRect.top;

    HWND window = CreateWindowExA(0, title, // Unique identifier again
                                    title, dwStyle, 100, 100, width, height, NULL, NULL, instance, NULL);

    QUARTZ_ASSERT(window != NULL, "Failed to create dummy window for OpenGL setup!");

    HDC dc = GetDC(window);
    QUARTZ_ASSERT(dc != NULL, "Failed to get DC!");

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

    QUARTZ_ASSERT(wglChoosePixelFormatARB(dc, pixelAttribs, 0, 1, &pixelFormat, &numPixelFormats),
                  "Failed call to 'wglChoosePixelFormatARB'");

    PIXELFORMATDESCRIPTOR pfd = {};
    DescribePixelFormat(dc, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

    QUARTZ_ASSERT(SetPixelFormat(dc, pixelFormat, &pfd), "Failed to SetPixelFormat");

    const int contextAttribs [] = {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
        WGL_CONTEXT_MINOR_VERSION_ARB, 3,
        WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB,
        0
    };

    HGLRC rc = wglCreateContextAttribsARB(dc, 0, contextAttribs);
    QUARTZ_ASSERT(rc != NULL, "Failed to create opengl context!");
    QUARTZ_ASSERT(wglMakeCurrent(dc, rc), "Failed to make current!");

    ShowWindow(window, SW_SHOW);

    quartz_implicit_context.running = true;
    
    quartz_implicit_context.window.width = width;
    quartz_implicit_context.window.height = height;
    quartz_implicit_context.window.window = window;
    quartz_implicit_context.window.dc = dc;
    quartz_implicit_context.window.rc = rc;
}

void quartz_update_events()
{
    MSG msg;

    while(PeekMessageA(&msg, quartz_implicit_context.window.window, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg); // Sends message to the callback function of the window
    }
}

void quartz_swap_buffers()
{
    SwapBuffers(quartz_implicit_context.window.dc);
}

static LRESULT CALLBACK quartz_windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    switch (msg)
    {
        case WM_CLOSE:
            quartz_implicit_context.running = false;
            break;
        case WM_SIZE:
        {
            RECT rect;
            GetClientRect(window, &rect);    
            quartz_implicit_context.window.width = rect.right - rect.left;
            quartz_implicit_context.window.height = rect.bottom - rect.top;
            break;
        }
        default:
            result = DefWindowProcA(window, msg, wParam, lParam);
            break;
    }

    return result;
}

#endif

bool quartz_is_running()
{
    return quartz_implicit_context.running;
}

int quartz_get_screen_width()
{
    return quartz_implicit_context.window.width;
}

int quartz_get_screen_height()
{
    return quartz_implicit_context.window.height;
}

GLuint quartz_shader_from_source(GLenum shader_type, const char* shader_src)
{
    GLuint id = glCreateShader(shader_type);
    glShaderSource(id, 1, &shader_src, nullptr);
    quartz_compile_shader(id);
    return id;
}

GLuint quartz_program_from_shaders(GLuint vs_id, GLuint fs_id, bool use_program_now)
{
    GLuint id = glCreateProgram();
    glAttachShader(id, vs_id);
    glAttachShader(id, fs_id);
    glLinkProgram(id);

    if(use_program_now)
        glUseProgram(id);

    return id;
}

void quartz_compile_shader(GLuint shader_id)
{
    glCompileShader(shader_id);

    int success;
    char shaderLog[2048];
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(shader_id, 2048, 0, shaderLog);
        QUARTZ_ASSERT(false, shaderLog);
    }
}