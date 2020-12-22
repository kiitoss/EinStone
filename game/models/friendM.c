#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
Friend get_new_friend(Friend_Spawner *spawner, int posX, int posY) {
  Friend f;
  
  f.id_friend = spawner->id_friend;
  f.ability = spawner->ability;
  f.delay_frame_ability = spawner->delay_frame_ability;
  f.delay_ability = spawner->delay_ability;
  f.life = spawner->life;
  f.attack = spawner->attack;
  f.range = spawner->range;
  f.posX = posX;
  f.posY = posY;

  f.animation_passive = MLV_create_animation_player(spawner->animation_passive);
  f.animation_ability = MLV_create_animation_player(spawner->animation_ability);
  
  f.is_passive = true;
  return f;
}
