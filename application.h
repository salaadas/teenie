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
};

#endif // APPLICATION_H_
