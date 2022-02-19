#ifndef LINALG_H_
#define LINALG_H_

typedef struct {
    int x, y;
} Vec2i;

Vec2i vec2i0();
Vec2i vec2i(int x, int y);
Vec2i vec2is(int x);
Vec2i vec2i_mult(Vec2i a, Vec2i b);
Vec2i vec2i_div(Vec2i a, Vec2i b);
Vec2i vec2i_add(Vec2i a, Vec2i b);
Vec2i vec2i_sub(Vec2i a, Vec2i b);

#endif // LINALG_H_