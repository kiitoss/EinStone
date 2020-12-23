#include "../gameHeader.h"
#include "../makhead.h"

void switch_enemy_behavior(Enemy *this) {
  if (this->is_walking) {
    set_enemy_animation(this, this->animation_attack);
  }
  else {
    set_enemy_animation(this, this->animation_walking);
  }
  this->is_walking = !this->is_walking;
}

/* GLOBAL */
void update_enemy_animation(Enemy *this, Row *row) {
  int gridY_far, gridY_close, i;
  bool friend_in_range = false;
  gridY_far = (this->posX + this->padding - this->range) / row->rectsize;
  gridY_close = (this->posX + this->padding) / row->rectsize;
  for (i=gridY_far; i < gridY_close; i++) {
    if (is_friend(&row->friends[i])) {
      friend_in_range = true;
      break;
    }
  }
  if (friend_in_range == this->is_walking) {
    switch_enemy_behavior(this);
  }
  MLV_update_animation_player(this->animation);
}
