#include <graphx.h>
#include <keypadc.h>
#include <tice.h>
#include <time.h>
#include <fileioc.h>


#include "player.h"
#include "map_render.h"
#include "gfx/global_palette.h"


#define TARGET_FRAME_TIME 33

clock_t frame_start;


void lock_fps(){
    clock_t elapsed = clock() - frame_start;
        int elapsed_ms = (elapsed * 1000) / CLOCKS_PER_SEC;
        
        if (elapsed_ms < TARGET_FRAME_TIME) {
            msleep(TARGET_FRAME_TIME - elapsed_ms);
        }
}
void init_comp_time_vars(){
    link_image_flipped = gfx_MallocSprite(link_width, link_height);
    current_anim_frame = 1;
    
    link_image = link_walk_down_1;
}
int main(){
  

    gfx_Begin();
    gfx_SetDrawBuffer();
    
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_SetTransparentColor(2);
    init_player();
    //compile-time vars
    init_comp_time_vars();

    //program loop here
    while(1){
        //keyboard scan at every frame
        kb_Scan();
        //quit sensing
        if(kb_Data[6] & kb_Clear){
            break;
        }
        //game logic
        player_update();
        //game drawing
        gfx_FillScreen(0xFF);
        
        player_draw();
        //tilemap drawing here
        
        update_map();
        //buffering frames
        gfx_BlitBuffer();

        //30 FPS frame limiter
        lock_fps();
    }
    
    gfx_BlitBuffer();

    gfx_End();
    return 0;
}