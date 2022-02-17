#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "SDL.h"
#include "../graphics.h"

class Texture
{
    public:
        Texture();
        Texture(Graphics &graphics, const char *file_path, 
                int source_x, int source_y,
                int width, int height);
        ~Texture();

        void render_texture(Graphics &graphics, int dest_x, int dest_y);
    private:
        SDL_Rect source_rect;
        SDL_Texture *texture_spritesheet;
};

#endif //  TEXTURE_H_