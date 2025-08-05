#ifndef PLAYER_H
#define PLAYER_H

#include <graphx.h>
#include <keypadc.h>
#include <stdbool.h>

extern gfx_sprite_t *link_image;
extern gfx_sprite_t *link_image_flipped;

extern int link_x;
extern int link_y;
extern double link_speed_up;
extern double link_speed_side;
extern int link_height;
extern int link_width;
extern int link_facing;
extern int current_anim_frame;
extern int total_anim_frames;

void init_link_arrays(void);
void link_draw(void);
void link_update(void);

#endif