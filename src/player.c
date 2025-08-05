#include <graphx.h>
#include <keypadc.h>



#include "gfx/link.h"
#include "player.h"
typedef struct gfx_sprite_t gfx_sprite_t;

gfx_sprite_t *link_image;

gfx_sprite_t *link_image_flipped;
gfx_sprite_t *placeholder;
int link_x = GFX_LCD_WIDTH / 2;
int link_y = GFX_LCD_HEIGHT / 2;
double link_speed_up = 2;
double link_speed_side = 2;
int link_height = 25;
int link_width = 20;
int link_facing = 0;
int current_anim_frame;
int total_anim_frames = 10;
int actual_anim_frames[] = {1, 3, 6, 9};
gfx_sprite_t *link_walk_down_frames[11];
gfx_sprite_t *link_walk_up_frames[11];
gfx_sprite_t *link_walk_side_frames[11];
gfx_sprite_t *link_idle_frames[4];



// link_facing variable: 0 for down, 1 for left, 2 for up, 3 for right


bool find_in_array(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;  // Found at index i
        }
    }
    return false;  // Not found
}
void init_link_arrays(){
    link_walk_down_frames[0] = placeholder;
    link_walk_down_frames[1] = link_walk_down_1;
    link_walk_down_frames[2] = link_walk_down_2;
    link_walk_down_frames[3] = link_walk_down_3;
    link_walk_down_frames[4] = link_walk_down_4;
    link_walk_down_frames[5] = link_walk_down_5;
    link_walk_down_frames[6] = link_walk_down_6;
    link_walk_down_frames[7] = link_walk_down_7;
    link_walk_down_frames[8] = link_walk_down_8;
    link_walk_down_frames[9] = link_walk_down_9;
    link_walk_down_frames[10] = link_walk_down_10;
    link_walk_up_frames[0] = placeholder;
    link_walk_up_frames[1] = link_walk_up_1;
    link_walk_up_frames[2] = link_walk_up_2;
    link_walk_up_frames[3] = link_walk_up_3;
    link_walk_up_frames[4] = link_walk_up_4;
    link_walk_up_frames[5] = link_walk_up_5;
    link_walk_up_frames[6] = link_walk_up_6;
    link_walk_up_frames[7] = link_walk_up_7;
    link_walk_up_frames[8] = link_walk_up_8;
    link_walk_up_frames[9] = link_walk_up_9;
    link_walk_up_frames[10] = link_walk_up_10;
    link_walk_side_frames[0] = placeholder;
    link_walk_side_frames[1] = link_walk_side_1;
    link_walk_side_frames[2] = link_walk_side_2;
    link_walk_side_frames[3] = link_walk_side_3;
    link_walk_side_frames[4] = link_walk_side_4;
    link_walk_side_frames[5] = link_walk_side_5;
    link_walk_side_frames[6] = link_walk_side_6;
    link_walk_side_frames[7] = link_walk_side_7;
    link_walk_side_frames[8] = link_walk_side_8;
    link_walk_side_frames[9] = link_walk_side_9;
    link_walk_side_frames[10] = link_walk_side_10;
    link_idle_frames[0] = placeholder;
    link_idle_frames[1] = link_idle_down;
    link_idle_frames[2] = link_idle_side;
    link_idle_frames[3] = link_idle_up;
    

    

}
int i = 1;
void link_anim_down(){
        //if it is the correct frame for animation, play it:
        
        if(find_in_array(actual_anim_frames, sizeof(total_anim_frames), current_anim_frame)){
            
            //finding the next frame
            link_image = link_walk_down_frames[i];
            
            //changing the next frame
            i++;
            if(i >total_anim_frames){i = 1;}
        }
}
void link_move_down(void){
    link_facing = 0;
    link_y += link_speed_up;
    if(link_y > GFX_LCD_HEIGHT-link_height){
        link_y = GFX_LCD_HEIGHT-link_height;
        }
    }



void link_anim_left(){
        
        if(find_in_array(actual_anim_frames, sizeof(total_anim_frames), current_anim_frame)){
            link_image = link_walk_side_frames[i];
            
            
            i++;
            if(i >total_anim_frames){i = 1;}
        }
    }
void link_move_left(){
    link_facing = 1;
    link_x -= link_speed_side;
    if(link_x < 0){
        link_x = 0;
        }

    }
void link_anim_right(){
        
        if(find_in_array(actual_anim_frames, sizeof(total_anim_frames), current_anim_frame)){
            link_image = link_walk_side_frames[i];
            
            
            i++;
            if(i >total_anim_frames){i = 1;}
        }
    }
void link_move_right(){
    link_facing = 3;
    link_x += link_speed_side;
        
    if(link_x > GFX_LCD_WIDTH-link_width){
            link_x = GFX_LCD_WIDTH-link_width;
        }
    }
void link_anim_up(){
        
        if(find_in_array(actual_anim_frames, sizeof(total_anim_frames), current_anim_frame)){
            link_image = link_walk_up_frames[i];
            
            
            i++;
            if(i >total_anim_frames){i = 1;}
        }
    }
void link_move_up(){
    link_facing = 2; 
    link_y -= link_speed_up;
    if(link_y < 0){
            link_y = 0;
        }
    }

void link_idle(){
    if(link_facing == 0){
        link_image = link_idle_down;
    }
    if(link_facing == 2){
        link_image = link_idle_up;
    }
    if(link_facing == 3){
        link_image = link_idle_side;
    }
    if(link_facing == 1){
        link_image = link_idle_side;
    }
}
void link_draw(void){
    if (link_facing != 3) {
        gfx_TransparentSprite(link_image, link_x, link_y);
        }
        if(link_facing == 3){
            gfx_FlipSpriteY(link_image, link_image_flipped);
            
            gfx_TransparentSprite(link_image_flipped, link_x, link_y);
        }
}
void link_update(void){
        if(kb_Data[7] & kb_Up){
            link_anim_up();
            link_move_up();
        }
        if(kb_Data[7] & kb_Down){
            link_anim_down();
            link_move_down();
        }
        
        if(kb_Data[7] & kb_Right){
            link_anim_right();
            link_move_right();
    
        }
        if(kb_Data[7] & kb_Left){
            link_anim_left();
            link_move_left();
        }
        if(kb_Data[7] & kb_Down && kb_Data[7] & kb_Right){
            
            link_y -= link_speed_up/2;
            link_x -= link_speed_side/2;

        }
        if(kb_Data[7] & kb_Down && kb_Data[7] & kb_Left){
            
            link_y -= link_speed_up/2;
            link_x += link_speed_side/2;
        }
        if(kb_Data[7] & kb_Up && kb_Data[7] & kb_Right){
            
            link_y += link_speed_up/2;
            link_x -= link_speed_side/2;
        }
        if(kb_Data[7] & kb_Up && kb_Data[7] & kb_Left){
            
            link_y += link_speed_up/2;
            link_x += link_speed_side/2;
        }
        if(!kb_Data[7]){
            link_idle();
        }
        current_anim_frame++;
        if(current_anim_frame>total_anim_frames){
            current_anim_frame = 1;
        }
}