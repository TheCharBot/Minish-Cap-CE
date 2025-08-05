#include "player.c"

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

void init_link_arrays(){}
bool find_in_array(){}
void link_anim_down(){}

