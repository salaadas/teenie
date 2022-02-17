#include "./checkcode.h"
#include <stdio.h>
#include "SDL.h"

int scc(int code)
{
    if (code < 0) {
        fprintf(stderr, "SDL ERROR: Something gone wrong:\n%s\n", SDL_GetError());
    }

    return code;
}

void *scp(void *ptr)
{
    if (ptr == NULL) {
        fprintf(stderr, "SDL ERROR: Something gone wrong:\n%s\n", SDL_GetError());
    }

    return ptr;
}