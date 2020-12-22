#include "../gameHeader.h"
#include "../makhead.h"

void draw_home(Game_Manager *GM, Texture_Manager *TM) {
  MLV_draw_image(TM->friend_home_background,GM->window.friend_home.posX, GM->window.friend_home.posY);
  MLV_draw_image(TM->enemy_home_background,GM->window.enemy_home.posX, GM->window.enemy_home.posY); 
}

void draw_friend_spawner(Game_Manager *GM, Texture_Manager *TM) {
  int i;

  MLV_draw_image(TM->friend_spawner_background,GM->window.friend_spawner.posX, GM->window.friend_spawner.posY);
  for (i=0;i<NB_FRIENDS;i++){
    MLV_draw_image(TM->friend_spawners_imgs[i],GM->window.friend_spawner.posX + i*GM->window.rectsize,GM->window.friend_spawner.posY);
  }
  
  
}

void draw_enemy_spawner(Game_Manager *GM, Texture_Manager *TM) {
  int i;

  MLV_draw_image(TM->enemy_spawner_background,GM->window.enemy_spawner.posX, GM->window.enemy_spawner.posY);

  for (i=0;i<NB_ENEMIES;i++){
    MLV_draw_image(TM->enemy_spawners_imgs[i],GM->window.enemy_spawner.posX + i*GM->window.rectsize,GM->window.enemy_spawner.posY);
  }
  
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
  draw_friend_spawner(GM,TM);
  GM->gamemode = MULTI; 
  if (GM->gamemode == MULTI) {
    draw_enemy_spawner(GM, TM);
  }
  draw_field(GM, TM);
}
