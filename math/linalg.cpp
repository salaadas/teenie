#include "./linalg.h"

Vec2i vec2i(int x, int y)
{
    Vec2i v2 {
        x, y
    };

    return v2;
}
Vec2i vec2i0()
{
    return vec2i(0, 0);
}
Vec2i Vec2is(int x)
{
    return vec2i(x, x);
}
Vec2i vec2i_mult(Vec2i a, Vec2i b)
{
    return vec2i(a.x * b.x, a.y * b.y);
}
Vec2i vec2i_div(Vec2i a, Vec2i b)
{
    return vec2i(a.x / b.x, a.y / b.y);
}
Vec2i vec2i_add(Vec2i a, Vec2i b)
{
    return vec2i(a.x + b.x, a.y + b.y);
}
Vec2i vec2i_sub(Vec2i a, Vec2i b)
{
    return vec2i(a.x - b.x, a.y - b.y);
}