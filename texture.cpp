#include "./texture.h"
#include "SDL.h"
#include "./graphics.h"
#include "./ultilities/checkcode.h"
#include "./globals.h"
#include "./math/linalg.h"

Texture::Texture()
{
}

Texture::~Texture()
{
}

Texture::Texture(Graphics &graphics, const char *file_path, 
                 Vec2i source_id, Vec2i dimensions)
{
    this->source_rect.x = source_id.x * globals::SPRITE_SIZE;
    this->source_rect.y = source_id.y * globals::SPRITE_SIZE;
    this->source_rect.w = dimensions.x;
    this->source_rect.h = dimensions.y;

    this->texture_spritesheet = SDL_CreateTextureFromSurface(
        graphics.emit_renderer(),
        graphics.get_surface_from_filepath(file_path));

    scp(this->texture_spritesheet);
}

void Texture::render_texture(Graphics &graphics, Vec2i destination)
{
    SDL_Rect dest_rect;
    dest_rect.x = destination.x;
    dest_rect.y = destination.y;
    dest_rect.h = this->source_rect.h * globals::SPRITE_SCALE;
    dest_rect.w = this->source_rect.w * globals::SPRITE_SCALE;

    graphics.blit_something(this->texture_spritesheet, &this->source_rect, &dest_rect);
}

SDL_Texture *Texture::emit_texture_spritesheet()
{
    return this->texture_spritesheet;
}
