#ifndef VOXELGAME_WINDOW_H
#define VOXELGAME_WINDOW_H

#include <string>

namespace window
{
    void init(int width, int height, const std::string& t);
    void dispose();

    bool is_running();

    void quit();
    void poll_events();
    void update();

    bool is_key_tapped(int key);
    bool is_key_pressed(int key);
    bool is_key_released(int key);

    int get_width();
    int get_height();
}

#endif //VOXELGAME_WINDOW_H
