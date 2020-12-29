#include "../../headers/global_header.h"



/* Met à jour l'attaque des ennemies en fonction de la difficulté. */
void set_enemy_attack(Game_Manager *GM,int attack){
  int i;
  for(i=0;i<NB_ENEMIES;i++){
    GM->enemy_spawners[i].attack += attack;
  }
}



/* Met à jour la vitesse des ennemies en fonction de la difficulté. */
void set_enemy_speed(Game_Manager *GM,int speed){
  int i;
  for(i=0;i<NB_ENEMIES;i++){
    GM->enemy_spawners[i].speed += speed;
  }
}



/* Met à jour la vie des ennemies en fonction de la difficulté. */
void set_enemy_life(Game_Manager *GM,int life){
  int i;
  for(i=0;i<NB_ENEMIES;i++){
    GM->enemy_spawners[i].life += life;
  }
}



/* Initialise l'IA. */
void init_IA(Game_Manager *GM){
  int attack,speed,life;

  speed = life = attack = 0;
  
  switch(GM->difficulty){
  case EASY:
    attack = -5;
    life = -10;
    speed = 0;
    GM->p1.life = LIFE_P1 + 1;
    break;
  case HARD:
    attack = 5;
    life = 10;
    speed = 1;
    GM->p1.life = (LIFE_P1 - 1 > 0) ? LIFE_P1 - 1 : 1;
    break;
  default:
    break;
  }
  set_enemy_attack(GM, attack);
  set_enemy_speed(GM, speed);
  set_enemy_life(GM, life);
}
