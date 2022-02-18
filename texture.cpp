#include "./texture.h"
#include "SDL.h"
#include "./graphics.h"
#include "./ultilities/checkcode.h"
#include "./globals.h"

Texture::Texture()
{
}

Texture::~Texture()
{
}

Texture::Texture(Graphics &graphics, const char *file_path, 
                int source_x, int source_y,
                int width, int height)
{
    this->source_rect.x = source_x;
    this->source_rect.y = source_y;
    this->source_rect.w = width;
    this->source_rect.h = height;

    this->texture_spritesheet = SDL_CreateTextureFromSurface(
        graphics.emit_renderer(),
        graphics.get_surface_from_filepath(file_path));

    scp(this->texture_spritesheet);
}

void Texture::render_texture(Graphics &graphics, int dest_x, int dest_y)
{
    SDL_Rect dest_rect;
    dest_rect.x = dest_x;
    dest_rect.y = dest_y;
    dest_rect.h = this->source_rect.h * globals::SPRITE_SCALE;
    dest_rect.w = this->source_rect.w * globals::SPRITE_SCALE;

    graphics.blit_something(this->texture_spritesheet, &this->source_rect, &dest_rect);
}

SDL_Texture *Texture::emit_texture_spritesheet()
{
    return this->texture_spritesheet;
}
