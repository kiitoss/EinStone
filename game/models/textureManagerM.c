#include "../gameHeader.h"
#include "../makhead.h"

MLV_Image *get_image_with_path(char *path) {
  MLV_Image *img = MLV_load_image(path);
  if (!img) {
    printf("--> L'image au chemin '%s' n'a pas pu être chargée.\n", path);
    exit(0);
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
  default:
    printf("--> Id friend inconnu.\n");
    exit(0);
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
  default:
    printf("--> Id ennemi inconnu.\n");
    path = "resources/sprites/skeleton_sprite.png";
    break;
  }
  return get_image_with_path(path);
}

MLV_Image **get_friend_spawners_sprites() {
  MLV_Image *friend_spawners_sprites[NB_FRIENDS];
  int i;
  
  return friend_spawners_sprites;
}

/* GLOBAL */
Texture_Manager init_TM() {
  int i;
  Texture_Manager TM;
  TM.field_light_grass_img = get_image_with_path("resources/backgrounds/light_grass.png");
  TM.field_dark_grass_img = get_image_with_path("resources/backgrounds/dark_grass.png");
  TM.enemy_spawner_background = get_image_with_path("resources/backgrounds/wood.png");
  TM.friend_spawner_background = get_image_with_path("resources/backgrounds/wood.png");
  TM.friend_home_background = get_image_with_path("resources/backgrounds/castle.jpg");
  TM.enemy_home_background = get_image_with_path("resources/backgrounds/castle.jpg");
  TM.gold_img = get_image_with_path("resources/pops/gold.png");
  TM.shot_img = get_image_with_path("resources/pops/arrow.png");
  for (i=0; i<NB_FRIENDS; i++) {
    TM.friend_spawners_sprites[i] = get_friend_spawner_sprite(i);
  }
  for (i=0; i<NB_ENEMIES; i++) {
    TM.enemy_spawners_sprites[i] = get_enemy_spawner_sprite(i);
  }
  printf("CA MARCHE\n");
  return TM;
}
