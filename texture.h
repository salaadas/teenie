#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "SDL.h"
#include "./graphics.h"
#include "./math/linalg.h"

class Texture
{
    public:
        Texture();
        Texture(Graphics &graphics, const char *file_path, 
                Vec2i source_id, Vec2i dimensions);
        ~Texture();

        void render_texture(Graphics &graphics, Vec2i destination);
        SDL_Texture *emit_texture_spritesheet();
    private:
        SDL_Rect source_rect;
        SDL_Texture *texture_spritesheet;
};

#endif //  TEXTURE_H_
