#include <graphx.h>
#include <keypadc.h>
#include <tice.h>
#include <time.h>
#include <fileioc.h>

#include "gfx/link.h"
#include "player.h"

#define TARGET_FRAME_TIME 33
#define CONCAT(a, b) a##b
clock_t frame_start;
void lock_fps(){
    clock_t elapsed = clock() - frame_start;
        int elapsed_ms = (elapsed * 1000) / CLOCKS_PER_SEC;
        
        if (elapsed_ms < TARGET_FRAME_TIME) {
            msleep(TARGET_FRAME_TIME - elapsed_ms);
        }
}
int main(){
    if (LINK_init() == 0)
    {
        return 1;
    }

    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_SetTransparentColor(2);
    init_link_arrays();
    //compile-time vars
    link_image_flipped = gfx_MallocSprite(link_width, link_height);
    current_anim_frame = 1;
    
    link_image = link_walk_down_1;
    //program loop here
    while(1){
        //keyboard scan at every frame
        kb_Scan();
        //quit sensing
        if(kb_Data[6] & kb_Clear){
            break;
        }
        //game logic
        link_update();
        //game drawing
        gfx_FillScreen(255);
        link_draw();
        //buffering frames
        gfx_BlitBuffer();

        //30 FPS frame limiter
        lock_fps();
    }
    
    gfx_BlitBuffer();

    gfx_End();
    return 0;
}