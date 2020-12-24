#include "../gameHeader.h"
#include "../makhead.h"

MLV_Image *get_image_with_path(char *path) {
  MLV_Image *img = MLV_load_image(path);
  if (!img) {
    printf("--> L'image au chemin '%s' n'a pas pu être chargée.\n", path);
    exit(1);
  }
  return img;
}

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

MLV_Image *get_spawner_img_from_sprite(MLV_Image *sprite, int rectsize, int spawner_height) {
  MLV_Image *spawner_img;
  spawner_img = MLV_copy_partial_image(sprite, 64, 3*64, 64, 64); 
  MLV_resize_image_with_proportions(spawner_img, rectsize, spawner_height);
  return spawner_img;
}

/* GLOBAL */
void set_img_size(MLV_Image *img, int width, int height) {
  MLV_resize_image(img, width, height);
}
void set_img_proportional_size(MLV_Image *img, int width, int height){
  MLV_resize_image_with_proportions(img, width, height);
}
/* GLOBAL */
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
  return TM;
}
