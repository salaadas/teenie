#ifndef TILEGRID_H_
#define TILEGRID_H_

#include "../texture.h"
#include "../graphics.h"
#include "../math/linalg.h"
#include <map>

class TileGrid
{
    public:
        TileGrid();
        TileGrid(Graphics &graphics);
        ~TileGrid();

        void render_tile(Graphics &graphics, const char *tile_name, Vec2i position);
    private:
        std::map<const char*, Texture> tiles;
};

#endif // TILEGRID_H_