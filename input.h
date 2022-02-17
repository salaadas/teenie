#ifndef INPUT_H_
#define INPUT_H_

#include <map>
#include "SDL.h"

class Input
{
    public:
        void refresh_keys_memory();

        void handle_key_press(const SDL_Event &event);
        void handle_key_release(const SDL_Event &event);

        bool was_key_pressed(SDL_Scancode key);
        bool was_key_released(SDL_Scancode key);
        bool is_key_held(SDL_Scancode key);
    private:
        std::map<SDL_Scancode, bool> held_keys;
        std::map<SDL_Scancode, bool> released_keys;
        std::map<SDL_Scancode, bool> pressed_keys;
};

#endif // INPUT_H_