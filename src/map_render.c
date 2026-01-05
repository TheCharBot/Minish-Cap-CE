#include <graphx.h>
#include <compression.h>



#include "map_render.h"
#include "tilemap/shf_csv.c"


//typedef struct gfx_tilemap_t gfx_tilemap_t;


//extern unsigned char tilemap_tiles[];
gfx_tilemap_t tilemap;

void decompress_appvars(){
    for (i = 0; i < sizeof(shf_tiles_compressed) / sizeof(gfx_sprite_t*); ++i)
    {
        tmp_ptr = gfx_MallocSprite(TILE_WIDTH, TILE_HEIGHT);
        zx0_Decompress(tmp_ptr, shf_tiles_compressed[i]);
        tileset_tiles[i] = tmp_ptr;
    }

}

int init_render(){
    
    

    if (mcmapsA_init() == 0)
    {
        return 1;
    }
    
    tilemap.map         = shf_csv;
    tilemap.tiles       = tileset_tiles;
    tilemap.type_width  = gfx_tile_16_pixel;
    tilemap.type_height = gfx_tile_16_pixel;
    tilemap.tile_height = TILE_HEIGHT;
    tilemap.tile_width  = TILE_WIDTH;
    tilemap.draw_height = TILEMAP_DRAW_HEIGHT;
    tilemap.draw_width  = TILEMAP_DRAW_WIDTH;
    tilemap.height      = TILEMAP_HEIGHT;
    tilemap.width       = TILEMAP_WIDTH;
    tilemap.y_loc       = Y_OFFSET;
    tilemap.x_loc       = X_OFFSET;
    decompress_appvars();
    


    
    return 0;
}

void update_map(){
    
    
    gfx_Tilemap_NoClip(&tilemap, X_OFFSET, Y_OFFSET);
}