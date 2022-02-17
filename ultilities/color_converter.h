#ifndef COLOR_CONVERTER_H_
#define COLOR_CONVERTER_H_

#include "SDL.h"
#include "math.h"

SDL_Color hex_to_rgba(int hex);

int rgba_to_hex(SDL_Color rgba);

#endif // COLOR_CONVERTER_H_