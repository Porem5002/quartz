#include <quartz.hpp>

constexpr int SIDE_CELL_COUNT = 50;
constexpr float TICK_COOLDOWN = 0.1f;

constexpr quartz_color ALIVE_COLOR = QUARTZ_WHITE;
constexpr quartz_color DEAD_COLOR = QUARTZ_BLACK;

constexpr quartz_color VALID_EDIT_COLOR = { 0.0, 1.0, 0.0, 0.7 };
constexpr quartz_color INVALID_EDIT_COLOR = { 1.0, 0.0, 0.0, 0.7 };

enum class game_mode
{
    EDIT,
    SIMULATION,
};

struct cell_data
{
    bool alive;
    bool should_switch;
};

static game_mode mode = game_mode::EDIT;
static cell_data cells [SIDE_CELL_COUNT][SIDE_CELL_COUNT] = {};

static quartz_ivec2 neighbour_offsets [8] = {
    { -1, 1 },  // Top Left
    { 0, 1 },   // Top
    { 1, 1 },   // Top Right
    
    { -1, -1 }, // Bottom Left
    { 0, -1 },  // Bottom
    { 1, -1 },  // Bottom Right

    { -1, 0 },  // Left
    { 1, 0 },   // Right
};

#define foreach_xy() \
    for(int y = 0; y < SIDE_CELL_COUNT; y++)\
        for(int x = 0; x < SIDE_CELL_COUNT; x++)

int main()
{
    quartz_start(500, 500, "Game Of Life");
    quartz_set_fixed_delta_time(TICK_COOLDOWN);

    auto screen_vp = quartz_get_screen_viewport();

    quartz_camera2D camera = quartz_init_camera2D(SIDE_CELL_COUNT, SIDE_CELL_COUNT);
    camera.x = SIDE_CELL_COUNT / 2.0 - 0.5;
    camera.y = -SIDE_CELL_COUNT / 2.0 + 0.5;

    quartz_render2D_init();
    quartz_render2D_set_camera(&camera);

    while(quartz_update())
    {
        quartz_clear(DEAD_COLOR);

        quartz_ivec2 screen_mouse_pos = quartz_get_mouse_pos();
        quartz_vec2 mouse_pos = quartz_camera2D_to_world_through_viewport(&camera, screen_mouse_pos, screen_vp);

        if(quartz_is_key_down(QUARTZ_KEY_SPACE))
        {
            mode = mode == game_mode::EDIT ? game_mode::SIMULATION : game_mode::EDIT;
        
            // In between simulation steps 'should_switch' is kept so that we can use it to resolve the cell state when we start the next step. 
            // If we pause, edit the cells and unpause, the simulation could still be considering the old 'should_switch' value, so we clear it to avoid this
            foreach_xy()
            {
                cells[x][y].should_switch = false;
            }
        }

        // Simulation code running on a fixed time step
        while(quartz_fixed_update())
        {
            if(mode != game_mode::SIMULATION) continue;

            // Resolve cell states
            foreach_xy()
            {
                cell_data& cell = cells[x][y];
                
                if(cell.should_switch)
                {
                    cell.alive = !cell.alive;
                    cell.should_switch = false;
                }
            }

            // Prepare next step
            foreach_xy()
            {
                quartz_ivec2 coords = {x, y};

                int neighbors_alive = 0;

                for(const auto& offset : neighbour_offsets)
                {
                    int wrapped_x = (coords.x + offset.x);
                    if(wrapped_x < 0) wrapped_x = SIDE_CELL_COUNT + wrapped_x;
                    if(wrapped_x >= SIDE_CELL_COUNT) wrapped_x = SIDE_CELL_COUNT - wrapped_x;

                    int wrapped_y = (coords.y + offset.y);
                    if(wrapped_y < 0) wrapped_y = SIDE_CELL_COUNT + wrapped_y;
                    if(wrapped_y >= SIDE_CELL_COUNT) wrapped_y = SIDE_CELL_COUNT - wrapped_y;

                    neighbors_alive += (int)cells[wrapped_x][wrapped_y].alive;
                }

                cell_data& cell = cells[x][y];

                bool should_die = cell.alive && (neighbors_alive != 2 && neighbors_alive != 3);
                bool should_become_alive = !cell.alive && neighbors_alive == 3;
                cell.should_switch = should_become_alive || should_die;
            }
        }

        // With the current implementation we check every cell individually to see if it is being hovered
        // this is used to only allow one cell to be hover even if the mouse is on the edge of two or more cells
        bool hovered_cell_this_frame = false;

        foreach_xy()
        {
            cell_data& cell = cells[x][y];
            quartz_vec2 pos = {(float)x,(float)-y};

            bool hovering_cell = !hovered_cell_this_frame && quartz_aabb2_touches_point(mouse_pos, { pos.x, pos.y, 0.5, 0.5 });
            hovered_cell_this_frame = hovered_cell_this_frame || hovering_cell;

            if(cell.alive) quartz_render2D_quad(ALIVE_COLOR, pos, {1,1});

            if(hovering_cell)
            {
                if(mode == game_mode::EDIT && quartz_is_key_down(QUARTZ_KEY_L_MOUSE_BTN))
                    cell.alive = !cell.alive;

                quartz_color hover_color = mode == game_mode::EDIT ? VALID_EDIT_COLOR : INVALID_EDIT_COLOR;
                quartz_render2D_quad(hover_color, pos, {1,1});
            }
        }

        quartz_render2D_flush();
    }

    return 0;
}