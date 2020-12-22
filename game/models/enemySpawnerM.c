#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
Enemy_Spawner init_ES(int id_enemy,TM *TM,Window window){
  Enemy_Spawner ES;

  switch(id_enemy){
  case 0:
    ES.life = 100;
    ES.attack = 20;
    ES.speed = 1;
    ES.price= 100;
    ES.delay_frame_attack = 0;
    ES.delay_attack = 60;
    ES.range = window.rextsize*1;
    
  default :printf("-->MAX atteint ! \n");break;
  }
  sprintf(ES.price_str, "%d",ES.price);

  ES.animation_attack = get_animation(TM.enemy_spawners_sprites[i], window.rectisize,13,0,6,10 );    
  ES.animation_walking = get_animation(TM.enemy_spawners_sprites[i], window.rectisize,9,0,9,10 );
  return ES;
}


