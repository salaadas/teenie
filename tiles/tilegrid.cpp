#include "./tilegrid.h"
#include "../texture.h"
#include "../graphics.h"
#include "../globals.h"
#include "../math/linalg.h"
#include <stdio.h>
#include <assert.h>

TileGrid::TileGrid()
{
}

TileGrid::~TileGrid()
{
}

TileGrid::TileGrid(Graphics &graphics)
{
    this->init_basic_tiles(graphics);
}

void TileGrid::init_basic_tiles(Graphics &graphics)
{
    this->tiles["grass"] = Texture(graphics, "assets/textures/texture_tiles.png",
                                   vec2i(3, 2),  vec2is(globals::SPRITE_SIZE));
    this->tiles["dirt"]  = Texture(graphics, "assets/textures/texture_tiles.png",
                                   vec2i(14, 2), vec2is(globals::SPRITE_SIZE));
    this->tiles["wall"]  = Texture(graphics, "assets/textures/texture_tiles.png",
                                   vec2i(3, 5),  vec2is(globals::SPRITE_SIZE));
}

void TileGrid::render_tile(Graphics &graphics, const char *tile_name, Vec2i position)
{
    //if ((int)this->tiles.count(tile_name) == 0) {
    //    fprintf(stderr, "TILE ERROR: Tile name does not exist: %s\n", tile_name);
    //     assert(0);
    //}

    this->tiles[tile_name].render_texture(graphics, position);
}
