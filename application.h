#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "./graphics.h"
// #include "./tiles/tilegrid.h"

class Application
{
    public:
        Application();
        ~Application();
    private:
        // TileGrid tiles;
        bool quit = false;

        void game_loop();

        void render_all(Graphics &graphics);
        void update_all(uint32_t elapsed_time);
};

#endif // APPLICATION_H_
