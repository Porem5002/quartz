#include <include/quartz.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#undef STB_IMAGE_IMPLEMENTATION

#include <quartz.cpp>
#include <quartz_math.cpp>
#include <quartz_renderer.cpp>
#include <quartz_window.cpp>
#include <quartz_input.cpp>
#include <glload.cpp>

#define GAME_WIDTH 320
#define GAME_HEIGHT 180

int main()
{
    quartz_start(1200, 720, "My Window");

    quartz_texture texture1 = quartz_load_texture("assets/TEXTURE_ATLAS.png");
    quartz_texture texture2 = quartz_load_texture("assets/terrain_atlas.png");

    quartz_render_init();

    float zoom_x = (float)quartz_get_screen_size().x  / (float)GAME_WIDTH;
    float zoom_y = (float)quartz_get_screen_size().y  / (float)GAME_HEIGHT;
    float zoom = min(zoom_x, zoom_y);

    quartz_camera2D cam = {};
    cam.width = quartz_get_screen_size().x;
    cam.height = quartz_get_screen_size().y;
    cam.zoom = zoom;

    quartz_mat4 proj = quartz_camera2D_to_mat4(cam);
    quartz_render_set_mvp(proj);

    quartz_sprite pixel = { texture1, {0, 0}, {1, 1} };
    quartz_sprite dice = { texture1, {16, 0}, {15, 16} };
    quartz_sprite tomatoes = { texture2, {388, 777}, {411 - 388, 797 - 777} };

    bool selector = true;

    while(quartz_is_running())
    {
        quartz_update_events();

        if(quartz_was_screen_resized())
        {
            auto screen_size = quartz_get_screen_size();

            float zoom_x = (float)screen_size.x  / (float)GAME_WIDTH;
            float zoom_y = (float)screen_size.y  / (float)GAME_HEIGHT;
            float zoom = min(zoom_x, zoom_y);

            cam.width = screen_size.x;
            cam.height = screen_size.y;
            cam.zoom = zoom;
            
            quartz_mat4 proj = quartz_camera2D_to_mat4(cam);
            quartz_render_set_mvp(proj);
            
            glViewport(0, 0, screen_size.x, screen_size.y);
        }

        printf("FPS: %f\n", 1.0f / quartz_get_delta_time());

        quartz_render_clear(0.2, 0.2, 0.23, 1.0);

        quartz_uvec2 screen_mouse_pos = quartz_get_mouse_pos();
        quartz_vec2 mouse_pos = quartz_screen_to_world2D(cam, screen_mouse_pos);

        if(quartz_is_key_down(QUARTZ_KEY_L_MOUSE_BTN))
            selector = !selector;

        static float rot = 0.0f;
        
        if(quartz_is_key_down(QUARTZ_KEY_R) || quartz_is_key_held(QUARTZ_KEY_R))
            rot += 5 * quartz_get_delta_time();
        
        quartz_render_sprite(selector ? dice : tomatoes, mouse_pos, {1.0f, 1.0f}, rot, QUARTZ_GREEN);

        quartz_render_flush();

        quartz_swap_buffers();
    }

    return 0;
}