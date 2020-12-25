#include "../../mainHeader.h"
#include "../makhead.h"

/* GLOBAL */
bool is_friend(Friend *this) {
  return this->id_friend != -1;
}

/* GLOBAL */
void set_friend_animation(Friend *this, MLV_Animation_player *animation) {
  this->animation = animation;
  MLV_play_animation_player(this->animation);
}

/* GLOBAL */
Friend get_new_friend(Friend_Spawner *spawner, int posX, int posY) {
  Friend f;
  
  f.id_friend = spawner->id_friend;
  f.ability = spawner->ability;
  f.DELAY_ABILITY = spawner->DELAY_ABILITY;
  f.delay_ability = spawner->DELAY_ABILITY;
  f.life = spawner->life;
  f.attack = spawner->attack;
  f.range = spawner->range;
  f.posX = posX;
  f.posY = posY;

  f.animation_passive = MLV_create_animation_player(spawner->animation_passive);
  f.animation_ability = MLV_create_animation_player(spawner->animation_ability);
  set_friend_animation(&f, f.animation_passive);
  f.is_passive = true;
  return f;
}
