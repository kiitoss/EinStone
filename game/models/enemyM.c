#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
void move_enemy(Enemy *this) {
  if (!this->is_walking) {
    return;
  }
  this->posX -= this->speed;
}

/* GLOBAL */
void set_enemy_animation(Enemy *this, MLV_Animation_player *animation) {
  this->animation = animation;
  MLV_play_animation_player(this->animation);
}

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
  e.DELAY_ATTACK = spawner->DELAY_ATTACK;
  e.delay_attack = spawner->DELAY_ATTACK;
  e.type_attack = spawner->type_attack;
  e.padding = spawner->padding;

  e.animation_attack = MLV_create_animation_player(spawner->animation_attack);
  e.animation_walking = MLV_create_animation_player(spawner->animation_walking);
  e.animation = e.animation_walking;
  MLV_play_animation_player(e.animation);
  return e;
}
