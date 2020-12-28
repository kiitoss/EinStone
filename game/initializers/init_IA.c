#include "../game_header.h"

void set_enemy_attack(Game_Manager *GM,int attack){
  int i;
  for(i=0;i<NB_ENEMIES;i++){
    GM->enemy_spawners[i].attack += attack;
  }
}

void set_enemy_speed(Game_Manager *GM,int speed){
  int i;
  for(i=0;i<NB_ENEMIES;i++){
    GM->enemy_spawners[i].speed += speed;
  }
}
void set_enemy_life(Game_Manager *GM,int life){
  int i;
  for(i=0;i<NB_ENEMIES;i++){
    GM->enemy_spawners[i].life += life;
  }
}

/* GLOBAL */
void init_IA(Game_Manager *GM){
  int attack,speed,life;

  speed=life=attack=0;
  
  switch(GM->difficulty){
  case EASY:
    attack = -5;
    life = -10;
    speed = 0;
    printf("EASY\n");
    break;
  case MEDIUM:
    printf("MEDIUM\n");
    break;
  case HARD:
    attack = 5;
    life = 10;
    speed = 1;
    printf("HARD\n");
    break;
  default:break;
  }
  set_enemy_attack(GM,attack);
  set_enemy_speed(GM,speed);
  set_enemy_life(GM,life);
  
}
