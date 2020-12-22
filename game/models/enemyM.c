#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
Enemy get_new_enemy(Enemy_Spawner *spawner, int posX, int posY) {
  Enemy e;

  e.life = spawner->life;
  e.attack = spawner->attack;
  e.speed = spawner->speed;
  e.range = spawner->range;
  e.posX = posX;
  e.posY = posY;
  e.is_walking = true;
  e.delay_frame_attack = spawner->delay_frame_attack;
  e.delay_attack = spawner->delay_attack;
  e.type_attack = spawner->type_attack;


  e.animation_attack = MLV_create_animation_player(spawner->animation_attack);
  e.animation_walking = MLV_create_animation_player(spawner->animation_walking);
  e.animation = e.animation_attack;
  MLV_play_animation_player(e.animation);
  return e;
}
