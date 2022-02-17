#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "./graphics.h"
#include "./tiles/texture.h"

class Application
{
    public:
        Application();
        ~Application();
    private:
        Texture grass, dirt; 

        bool quit = false;

        void game_loop();

        void render_all(Graphics &graphics);
};

#endif // APPLICATION_H_