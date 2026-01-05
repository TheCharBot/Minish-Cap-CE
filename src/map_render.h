#ifndef MAP_RENDER_H
#define MAP_RENDER_H
#include "gfx/shf_map.h"


#define TILE_WIDTH          16
#define TILE_HEIGHT         16

#define TILEMAP_WIDTH       62
#define TILEMAP_HEIGHT      43

#define TILEMAP_DRAW_WIDTH  20
#define TILEMAP_DRAW_HEIGHT 14

#define Y_OFFSET            16
#define X_OFFSET            0


extern unsigned char shf_csv[];
extern gfx_sprite_t *tmp_ptr;
extern unsigned int i;

extern gfx_sprite_t *tileset_tiles[128];
extern gfx_tilemap_t tilemap;
extern void decompress_appvars(void);
extern int init_render(void);
extern void update_map(void);
#endif