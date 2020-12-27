#include "../../mainHeader.h"
#include "../makhead.h"

MLV_Animation *get_animation(MLV_Image *sprite, int rectsize, int row_animation, int first_frame, int last_frame, int time) {
  int i;
  MLV_Image *images[MAX_FRAMES];
  MLV_Animation *animation;
  MLV_Sound *sound;
  int nb_frames;
  
  nb_frames = last_frame - first_frame;
  if (nb_frames > MAX_FRAMES) {
    first_frame = MAX_FRAMES - last_frame;
  }
  
  if (!sprite) {
    printf("--> L'image n'a pas pu être chargée.\n");
    exit(1);
  }
  
  animation = MLV_create_animation(nb_frames, 1, 1);
  for (i=0; i<nb_frames; i++) {
    images[i] = MLV_copy_partial_image(sprite, 64*(i+first_frame), 64*row_animation, 64, 64);
    MLV_resize_image(images[i], rectsize, rectsize);
    MLV_add_frame_in_animation(images+i, &sound, time, animation);
  }
  return animation;
}


/* GLOBAL */
void set_enemy_spawner_animations(Enemy_Spawner *ES, Texture_Manager *TM, Window *window, int index_enemy) {
  int row_animation_attack, first_frame_attack, last_frame_attack, time_attack;
  switch (ES->type_attack) {
  case CAC:
    row_animation_attack = 13;
    first_frame_attack = 0;
    last_frame_attack = 6;
    time_attack = 2;
    break;
  case DISTANCE:
    row_animation_attack = 5;
    first_frame_attack = 0;
    last_frame_attack = 7;
    time_attack = 2;
    break;
  default:
    row_animation_attack = 13;
    first_frame_attack = 0;
    last_frame_attack = 6;
    time_attack = 2;
    break;
  }
  
  ES->animation_attack = get_animation(TM->enemy_spawners_sprites[index_enemy], window->rectsize,row_animation_attack, first_frame_attack, last_frame_attack, time_attack);    
  ES->animation_walking = get_animation(TM->enemy_spawners_sprites[index_enemy], window->rectsize, 9, 0, 9, 2);
}



/* GLOBAL */
void set_friend_spawner_animations(Friend_Spawner *FS, Texture_Manager *TM, Window *window, int index_friend) {
  int row_animation_ability, first_frame_ability, last_frame_ability, time_ability;
  switch (FS->ability) {
  case MONEY:
    row_animation_ability = 3;
    first_frame_ability = 0;
    last_frame_ability = 7;
    time_ability = 2;
    FS->DELAY_ABILITY = 10000;
    break;
  case ATTACK:
    row_animation_ability = 19;
    first_frame_ability = 0;
    last_frame_ability = 14;
    time_ability = 2;
    FS->DELAY_ABILITY = 1300;
    break;
  case DEFENSE:
    row_animation_ability = 7;
    first_frame_ability = 0;
    last_frame_ability = 7;
    time_ability = 2;
    FS->DELAY_ABILITY = 700;
    break;
  default:
    row_animation_ability = 3;
    first_frame_ability = 0;
    last_frame_ability = 7;
    time_ability = 2;
    FS->DELAY_ABILITY = 10000;
    break;
  }
  FS->animation_passive = get_animation(TM->friend_spawners_sprites[index_friend], window->rectsize, 3, 1, 3, 5);
  
  FS->animation_ability = get_animation(TM->friend_spawners_sprites[index_friend], window->rectsize, row_animation_ability, first_frame_ability, last_frame_ability, time_ability);
}


/* GLOBAL */
Friend_Spawner init_FS(int index_friend, Texture_Manager *TM, Window *window) {
  Friend_Spawner FS;
  switch (index_friend) {
  case 0:
    FS.id_friend = 1;
    FS.ability = MONEY;
    FS.life = 50;
    FS.attack = 0;
    FS.price = 50;
    FS.range = 0;
    break;
  case 1:
    FS.id_friend = 2;
    FS.ability = ATTACK;
    FS.life = 100;
    FS.attack = 35;
    FS.price = 100;
    FS.range = window->rectsize*NB_COLUMNS;
    break;
  case 2:
    FS.id_friend = 3;
    FS.ability = DEFENSE;
    FS.life = 200;
    FS.attack = 20;
    FS.price = 75;
    FS.range = window->rectsize*1;
    break;
  case 3:
    FS.id_friend = 4;
    FS.ability = ATTACK;
    FS.life = 150;
    FS.attack = 50;
    FS.price = 150;
    FS.range = window->rectsize*NB_COLUMNS;
    break;
  default:
    printf("--> Maximum friends dépassé !\n");
    exit(1);
    break;
  }
  
  sprintf(FS.price_str, "%d", FS.price);
  
  set_friend_spawner_animations(&FS, TM, window, index_friend);
  return FS;
}





/* GLOBAL */
Enemy_Spawner init_ES(int index_enemy, Texture_Manager *TM, Window *window){
  Enemy_Spawner ES;
  switch(index_enemy){
  case 0:
    ES.id_enemy = 1;
    ES.life = 100;
    ES.attack = 20;
    ES.speed = 2;
    ES.price= 100;
    ES.DELAY_ATTACK = 600;
    ES.range = window->rectsize/4;
    ES.padding = window->rectsize/2;
    ES.type_attack = CAC;
    ES.score = 10;
    break;
  case 1:
    ES.id_enemy = 2;
    ES.life = 150;
    ES.attack = 50;
    ES.speed = 2;
    ES.price = 150;
    ES.DELAY_ATTACK = 600;
    ES.range = window->rectsize/4;
    ES.type_attack = DISTANCE;
    ES.padding = window->rectsize/2;
    ES.score = 10;
    break;
  case 2:
    ES.id_enemy = 3;
    ES.life = 150;
    ES.attack = 75;
    ES.speed = 1;
    ES.price = 175;
    ES.DELAY_ATTACK = 600;
    ES.range = window->rectsize/4;
    ES.type_attack = CAC;
    ES.padding = window->rectsize/2;
    ES.score = 10;
    break;
  default:
    printf("-->MAX atteint ! \n");
    break;
  }
  sprintf(ES.price_str, "%d",ES.price);

  set_enemy_spawner_animations(&ES, TM, window, index_enemy);
  
  return ES;
}
