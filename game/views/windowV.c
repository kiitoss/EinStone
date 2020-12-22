#include "../gameHeader.h"
#include "../makhead.h"

void draw_home(Game_Manager *GM, Texture_Manager *TM) {
  
}

void draw_friend_spawner(Game_Manager *GM, Texture_Manager *TM) {
  
}

void draw_enemy_spawner(Game_Manager *GM, Texture_Manager *TM) {
  
}

void draw_field(Game_Manager *GM, Texture_Manager *TM) {
  int i, j;
  MLV_Image *img;
  for (i=0; i<NB_ROWS; i++) {
    for (j=0; j<NB_COLUMNS; j++) {
      img = ((i+j)%2) ? TM->field_light_grass_img : TM->field_dark_grass_img;
      MLV_draw_image(img, GM->window.field.posX + j*GM->window.rectsize, GM->window.field.posY + i*GM->window.rectsize);
    }
  }
}

/* GLOBAL */
void draw_window(Game_Manager *GM, Texture_Manager *TM) {
  draw_home(GM, TM);
  draw_friend_spawner(GM, TM);
  if (GM->gamemode == MULTI) {
    draw_enemy_spawner(GM, TM);
  }
  draw_field(GM, TM);
}
