#include "./graphics.h"
#include "./globals.h"
#include "./ultilities/checkcode.h"
#include "./ultilities/color_converter.h"

#include "SDL_image.h"

#include <stdio.h>

Graphics::Graphics()
{
    this->window = SDL_CreateWindow(
        "idk yet", 0, 0, globals::WIDTH, globals::HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
    );
    scp(this->window);

    this->renderer = SDL_CreateRenderer(
        this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    scp(this->renderer);
    SDL_RenderSetLogicalSize(this->renderer, globals::WIDTH, globals::HEIGHT);

    SDL_Surface *pizza_surface = IMG_Load("assets/textures/pizza.png");
    this->cursor = SDL_CreateColorCursor(pizza_surface, 0, 0);
    scp(this->cursor);
    SDL_SetCursor(this->cursor);
}

void Graphics::clear()
{
    SDL_RenderClear(this->renderer);
}

void Graphics::flip()
{
    SDL_RenderPresent(this->renderer);
}

void Graphics::set_render_color(int color)
{
    SDL_Color new_color = hex_to_rgba(color);
    SDL_SetRenderDrawColor(this->renderer, new_color.r, new_color.g, new_color.b, new_color.a);
}

void Graphics::blit_something(SDL_Texture *texture, SDL_Rect *source_rect, SDL_Rect *dest_rect)
{
    SDL_RenderCopy(this->renderer, texture, source_rect, dest_rect);
}

SDL_Renderer *Graphics::emit_renderer()
{
    return this->renderer;
}

SDL_Surface *Graphics::get_surface_from_filepath(const char *filepath)
{
    if (this->spritesheets.count(filepath) == 0) {
        this->spritesheets[filepath] = IMG_Load(filepath);
        printf("Loaded new spritesheet\n");
    }

    return this->spritesheets[filepath];
}

Graphics::~Graphics()
{
    SDL_FreeCursor(this->cursor);
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}