#include "./color_converter.h"
#include "SDL.h"
#include "math.h"

SDL_Color hex_to_rgba(int hex)
{
    SDL_Color rgba;
    rgba.r = (hex >> 24) & 0xff;
    rgba.g = (hex >> 16) & 0xff;
    rgba.b = (hex >> 8)  & 0xff;
    rgba.a = (hex >> 0)  & 0xff;

    return rgba;
}

int rgba_to_hex(SDL_Color rgba)
{
    return (int)(pow(rgba.r, 4) + pow(rgba.g, 3) + pow(rgba.b, 2) + pow(rgba.a, 1));
}