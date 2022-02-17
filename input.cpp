#include "./input.h"
#include "SDL.h"

void Input::refresh_keys_memory()
{
    this->pressed_keys.clear();
    this->released_keys.clear();
}

void Input::handle_key_press(const SDL_Event &event)
{
    SDL_Scancode scancode = event.key.keysym.scancode;
    this->pressed_keys[scancode] = true;
    this->held_keys[scancode] = true;
}

void Input::handle_key_release(const SDL_Event &event)
{
    SDL_Scancode scancode = event.key.keysym.scancode;
    this->released_keys[scancode] = true;
    this->held_keys[scancode] = false;
}

bool Input::was_key_pressed(SDL_Scancode key)
{
    return this->pressed_keys[key];
}

bool Input::was_key_released(SDL_Scancode key)
{
    return this->released_keys[key];
}

bool Input::is_key_held(SDL_Scancode key)
{
    return this->held_keys[key];
}