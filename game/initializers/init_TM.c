#include "../../headers/global_header.h"



/* Charge et retourne une nouvelle image. */
MLV_Image *get_image_with_path(char *path) {
  MLV_Image *img = MLV_load_image(path);
  if (!img) {
    printf("--> L'image au chemin '%s' n'a pas pu être chargée.\n", path);
    exit(1);
  }
  return img;
}



/* Récupère tous les sprites des alliés. */
MLV_Image *get_friend_spawner_sprite(int id_friend) {
  char *path;
  switch (id_friend) {
  case 0:
    path = "resources/sprites/wife_sprite.png";
    break;
  case 1:
    path = "resources/sprites/bowman_sprite.png";
    break;
  case 2:
    path = "resources/sprites/tank_sprite.png";
    break;
  case 3:
    path = "resources/sprites/bowgirl_sprite.png";
    break;
  default:
    printf("--> Id friend inconnu.\n");
    exit(1);
    break;
  }
  return get_image_with_path(path);
}



/* Récupère tous les sprites des ennemies. */
MLV_Image *get_enemy_spawner_sprite(int id_enemy) {
  char *path;
  switch (id_enemy) {
  case 0:
    path = "resources/sprites/skeleton_sprite.png";
    break;
  case 1:
    path = "resources/sprites/skeleton_armor_sprite.png";
    break;
  case 2:
    path = "resources/sprites/orc_sprite.png";
    break;
  default:
    printf("--> Id ennemi inconnu.\n");
    path = "resources/sprites/skeleton_sprite.png";
    break;
  }
  return get_image_with_path(path);
}



/* Retourne l'image du spawner depuis un sprite. */
MLV_Image *get_spawner_img_from_sprite(MLV_Image *sprite, int rectsize, int spawner_height) {
  MLV_Image *spawner_img;
  spawner_img = MLV_copy_partial_image(sprite, 64, 3*64, 64, 64); 
  MLV_resize_image_with_proportions(spawner_img, rectsize, spawner_height);
  return spawner_img;
}



/* Change la taille de l'image. */
void set_img_size(MLV_Image *img, int width, int height) {
  MLV_resize_image(img, width, height);
}



/* Change la taille de l'image en conservant les proportions. */
void set_img_proportional_size(MLV_Image *img, int width, int height){
  MLV_resize_image_with_proportions(img, width, height);
}



/* Retourne l'ecran de pause. */
Pause_Screen get_pause_screen(Window window) {
  Geometry g;
  Pause_Screen pause_screen;
  g.posX = 3*window.width/8;
  g.posY = 4*window.height/12;
  g.width = window.width/4;
  g.height = window.height/12;
  pause_screen.play_btn = get_new_button(g, "Play", MLV_COLOR_YELLOW, MLV_COLOR_BROWN, "resources/font/Amatic-Bold.ttf", PAUSE_PLAY);
  g.posY += 2*window.height/12;
  pause_screen.save_quit_btn = get_new_button(g, "Save and Quit", MLV_COLOR_YELLOW, MLV_COLOR_BROWN, "resources/font/Amatic-Bold.ttf", PAUSE_SAVE_QUIT);
  g.posY += 2*window.height/12;
  pause_screen.quit_btn = get_new_button(g, "Quit", MLV_COLOR_YELLOW, MLV_COLOR_BROWN, "resources/font/Amatic-Bold.ttf", PAUSE_QUIT);
  pause_screen.hover_btn = NULL;
  return pause_screen;
}



/* Retourne l'ecran de Game Over. */
Game_Over get_game_over_screen(Window window) {
  Geometry g;
  Game_Over GO_screen;
  g.posX = 3*window.width/8;
  g.posY = 4*window.height/12;
  g.width = window.width/4;
  g.height = window.height/12;
  GO_screen.restart_btn = get_new_button(g, "Restart", MLV_COLOR_YELLOW, MLV_COLOR_BROWN, "resources/font/Amatic-Bold.ttf", RESTART);
  g.posY += 2*window.height/12;
  GO_screen.quit_btn = get_new_button(g, "Quit", MLV_COLOR_YELLOW, MLV_COLOR_BROWN, "resources/font/Amatic-Bold.ttf", PAUSE_QUIT);
  GO_screen.hover_btn = NULL;
  return GO_screen;
}



/* Initialise et retourne le gestionnaire d'images. */
Texture_Manager init_TM(Window window) {
  int i;
  Texture_Manager TM;
  TM.field_light_grass_img = get_image_with_path("resources/backgrounds/light_grass.png");
  set_img_size(TM.field_light_grass_img, window.rectsize, window.rectsize);

  TM.field_dark_grass_img = get_image_with_path("resources/backgrounds/dark_grass.png");
  set_img_size(TM.field_dark_grass_img, window.rectsize, window.rectsize);

  TM.enemy_spawner_background = get_image_with_path("resources/backgrounds/wood.png");
  set_img_size(TM.enemy_spawner_background,window.field.width, window.rectsize);

  TM.friend_spawner_background = get_image_with_path("resources/backgrounds/wood.png");
  set_img_size(TM.friend_spawner_background, window.field.width, window.rectsize);

  TM.friend_home_background = get_image_with_path("resources/backgrounds/castle.jpg");
  set_img_size(TM.friend_home_background, window.friend_home.width, window.friend_home.height);
  
  TM.enemy_home_background = get_image_with_path("resources/backgrounds/enemies.png");
  set_img_size(TM.enemy_home_background, window.enemy_home.width, window.enemy_home.height);

  TM.life_friend_img = get_image_with_path("resources/backgrounds/life.png");
  set_img_size(TM.life_friend_img, window.rectsize/6, window.rectsize/6);

  TM.delete_friend_img = get_image_with_path("resources/backgrounds/delete.png");
  set_img_size(TM.delete_friend_img, window.rectsize/2, window.rectsize/2);
  
  TM.gold_img = get_image_with_path("resources/pops/gold.png");
  set_img_size(TM.gold_img, window.rectsize/2, window.rectsize/2);

  TM.shot_img = get_image_with_path("resources/pops/arrow.png");
  set_img_proportional_size(TM.shot_img, window.rectsize/2, window.rectsize/2);
  
  TM.score_img = get_image_with_path("resources/pops/gold.png");
  set_img_size(TM.score_img, window.rectsize/4, window.rectsize/4);

  TM.font_size= 20;
  TM.font = MLV_load_font ("resources/font/AdobeDevanagari-Bold.otf", TM.font_size);
  
  for (i=0; i<NB_FRIENDS; i++) {
    TM.friend_spawners_sprites[i] = get_friend_spawner_sprite(i);
    TM.friend_spawners_imgs[i] = get_spawner_img_from_sprite(TM.friend_spawners_sprites[i], window.rectsize, window.friend_spawner.height);
  }
  for (i=0; i<NB_ENEMIES; i++) {
    TM.enemy_spawners_sprites[i] = get_enemy_spawner_sprite(i);
    TM.enemy_spawners_imgs[i] = get_spawner_img_from_sprite(TM.enemy_spawners_sprites[i], window.rectsize, window.enemy_spawner.height);
  }

  TM.pause_screen = get_pause_screen(window);
  TM.game_over_screen = get_game_over_screen(window);
  return TM;
}



/* Libère toutes les images chargées. */
void free_TM(Texture_Manager *this) {
  int i;
  MLV_free_image(this->field_light_grass_img);
  MLV_free_image(this->field_dark_grass_img);
  MLV_free_image(this->enemy_spawner_background);
  MLV_free_image(this->friend_spawner_background);
  MLV_free_image(this->enemy_home_background);
  MLV_free_image(this->friend_home_background);

  for (i=0; i<NB_FRIENDS; i++) {
    MLV_free_image(this->friend_spawners_sprites[i]);
    MLV_free_image(this->friend_spawners_imgs[i]);
  }

  for (i=0; i<NB_ENEMIES; i++) {
    MLV_free_image(this->enemy_spawners_sprites[i]);
    MLV_free_image(this->enemy_spawners_imgs[i]);
  }
  MLV_free_image(this->gold_img);
  MLV_free_image(this->shot_img);
  MLV_free_image(this->life_friend_img);
  MLV_free_image(this->delete_friend_img);
  MLV_free_image(this->score_img);

  MLV_free_font(this->font);
}
