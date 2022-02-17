#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "SDL.h"
#include <map>

class Graphics
{
    public:
        Graphics();
        ~Graphics();

        void clear();
        void flip();
        void blit_something(SDL_Texture *texture, SDL_Rect *source_rect, SDL_Rect *dest_rect);
        void set_render_color(int color);
        
        SDL_Renderer *emit_renderer();
        SDL_Surface *get_surface_from_filepath(const char *filepath);
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Cursor *cursor;
        std::map<const char*, SDL_Surface*> spritesheets;
};

#endif // GRAPHICS_H_
