#ifndef TILEGRID_H_
#define TILEGRID_H_

#include "../texture.h"
#include "../graphics.h"
#include "../math/linalg.h"
#include <map>

struct cmp_str
{
   bool operator()(char const *a, char const *b) const
   {
      return strcmp(a, b) < 0;
   }
};

class TileGrid
{
    public:
        TileGrid();
        TileGrid(Graphics &graphics);
        ~TileGrid();

        void render_tile(Graphics &graphics, const char *tile_name, Vec2i position);
    private:
        std::map<const char*, Texture, cmp_str> tiles;
        void init_basic_tiles(Graphics &graphics);
};

#endif // TILEGRID_H_
