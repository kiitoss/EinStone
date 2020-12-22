#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
Friend_Spawner init_FS(int index_friend, Texture_Manager *TM, Window *window) {
  Friend_Spawner FS;
  int row_animation_ability, first_frame_ability, last_frame_ability, time_ability;
  switch (index_friend) {
  case 0:
    FS.id_friend = 1;
    FS.ability = MONEY;
    FS.life = 50;
    FS.attack = 0;
    FS.price = 50;
    FS.delay_ability = 1000;
    FS.delay_frame_ability = 0;
    FS.range = 0;
    break;
  case 1:
    FS.id_friend = 2;
    FS.ability = ATTACK;
    FS.life = 100;
    FS.attack = 35;
    FS.price = 100;
    FS.delay_ability = 100;
    FS.delay_frame_ability = 0;
    FS.range = window->rectsize*NB_COLUMNS;
    break;
  case 2:
    FS.id_friend = 3;
    FS.ability = DEFENSE;
    FS.life = 200;
    FS.attack = 20;
    FS.price = 75;
    FS.delay_ability = 70;
    FS.delay_frame_ability = 0;
    FS.range = window->rectsize*1;
    break;
  case 3:
    FS.id_friend = 4;
    FS.ability = ATTACK;
    FS.life = 150;
    FS.attack = 50;
    FS.price = 150;
    FS.delay_ability = 100;
    FS.delay_frame_ability = 0;
    FS.range = window->rectsize*NB_COLUMNS;
    break;
  default:
    printf("--> Maximum friends dépassé !\n");
    exit(1);
    break;
  }
  
  sprintf(FS.price_str, "%d", FS.price);
  
  switch (FS.ability) {
  case MONEY:
    row_animation_ability = 3;
    first_frame_ability = 0;
    last_frame_ability = 7;
    time_ability = 10;
    break;
  case ATTACK:
    row_animation_ability = 19;
    first_frame_ability = 0;
    last_frame_ability = 13;
    time_ability = 8;
    break;
  case DEFENSE:
    row_animation_ability = 0;
    first_frame_ability = 8;
    last_frame_ability = 10;
    time_ability = 10;
    break;
  default:
    row_animation_ability = 3;
    first_frame_ability = 0;
    last_frame_ability = 2;
    time_ability = 20;
    break;
  }
  FS.animation_passive = get_animation(TM->friend_spawners_sprites[index_friend], window->rectsize, 3, 1, 3, 15);
  
  FS.animation_ability = get_animation(TM->friend_spawners_sprites[index_friend], window->rectsize, row_animation_ability, first_frame_ability, last_frame_ability, time_ability);
  return FS;
}





/* GLOBAL */
Enemy_Spawner init_ES(int index_enemy, Texture_Manager *TM, Window *window){
  Enemy_Spawner ES;
  int row_animation_attack, first_frame_attack, last_frame_attack, time_attack;
  switch(index_enemy){
  case 0:
    ES.life = 100;
    ES.attack = 20;
    ES.speed = 2;
    ES.price= 100;
    ES.delay_frame_attack = 0;
    ES.delay_attack = 60;
    ES.range = window->rectsize*1;
    ES.type_attack = CAC;
    break;
  case 1:
    ES.life = 150;
    ES.attack = 50;
    ES.speed = 2;
    ES.price = 150;
    ES.delay_frame_attack = 0;
    ES.delay_attack = 60;
    ES.range = window->rectsize*1;
    ES.type_attack = DISTANCE;
    break;
  case 2:
    ES.life = 150;
    ES.attack = 75;
    ES.speed = 1;
    ES.price = 200;
    ES.delay_frame_attack = 0;
    ES.delay_attack = 60;
    ES.range = window->rectsize*1;
    ES.type_attack = CAC;
    break;
  default:
    printf("-->MAX atteint ! \n");
    break;
  }
  sprintf(ES.price_str, "%d",ES.price);

  switch (ES.type_attack) {
  case CAC:
    row_animation_attack = 13;
    first_frame_attack = 0;
    last_frame_attack = 6;
    time_attack = 10;
    break;
  case DISTANCE:
    row_animation_attack = 5;
    first_frame_attack = 0;
    last_frame_attack = 7;
    time_attack = 10;
    break;
  default:
    row_animation_attack = 13;
    first_frame_attack = 0;
    last_frame_attack = 6;
    time_attack = 10;
    break;
  }
  
  ES.animation_attack = get_animation(TM->enemy_spawners_sprites[index_enemy], window->rectsize,row_animation_attack, first_frame_attack, last_frame_attack, time_attack);    
  ES.animation_walking = get_animation(TM->enemy_spawners_sprites[index_enemy], window->rectsize,9,0,9,10 );
  return ES;
}
