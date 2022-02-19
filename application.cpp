#include "SDL.h"
#include "./application.h"
#include "./graphics.h"
#include "./globals.h"
#include "./input.h"
#include "./texture.h"
#include "./math/linalg.h"

namespace {
    const int FPS = 60;
    const uint32_t MAX_FRAME_TIME = 1000 / FPS;
}

Application::Application()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->game_loop();
}

Application::~Application()
{
    SDL_Quit();
}

void Application::game_loop()
{
    Graphics game_graphics;
    Input input;

    this->grass = Texture(game_graphics, "assets/textures/texture_tiles.png", 
                          0, 0, 16, 16);
    this->dirt = Texture(game_graphics, "assets/textures/texture_tiles.png",
                         16, 0, 16, 16);

    uint32_t LAST_UPDATE_TIME = SDL_GetTicks();

    while (!this->quit) {
        SDL_Event event = {0};

        input.refresh_keys_memory();

        while (SDL_PollEvent(&event)) { 
            switch (event.type) {
                case SDL_QUIT: {
                    this->quit = true;
                }break;
                case SDL_KEYDOWN: {
                    input.handle_key_press(event);
                }break;
                case SDL_KEYUP: {
                    input.handle_key_release(event);
                }break;
                case SDL_MOUSEBUTTONDOWN: {
                    Vec2i m_coord = game_graphics.emit_mouse_coordinate();
                    SDL_GetMouseState(&m_coord.x, &m_coord.y);
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        printf("left clicked at: (%d; %d)\n", m_coord.x, m_coord.y);
                    }
                    if (event.button.button == SDL_BUTTON_RIGHT) {
                        printf("right clicked: (%d; %d)\n", m_coord.x, m_coord.y);
                    }
                }break;
                case SDL_MOUSEBUTTONUP: {
                }
            }
            if (input.was_key_pressed(SDL_SCANCODE_ESCAPE)) {
                this->quit = true;
            }
        }

        const uint32_t CURRENT_TIME = SDL_GetTicks();
        const uint32_t ELAPSED_TIME = CURRENT_TIME - LAST_UPDATE_TIME;

        this->render_all(game_graphics);
    }
}

void Application::render_all(Graphics &graphics)
{
    graphics.set_render_color(globals::BACKGROUND_COLOR);
    graphics.clear();
    // render entities/tiles after this line

    this->grass.render_texture(graphics, 100, 100);
    this->dirt.render_texture(graphics, 100 + 32, 100);

    // everything should be rendered by the time it reaches this comment
    graphics.flip();
}
