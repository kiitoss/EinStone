#include "../gameHeader.h"
#include "../makhead.h"

void use_friend_ability(Friend *this, Row *row) {
  switch (this->ability) {
  case DEFENSE:
    break;
  case ATTACK:
    break;
  case MONEY:
    break;
  default:
    break;
  }
}

void switch_friend_behavior(Friend *this) {
  if (this->is_passive) {
    set_friend_animation(this, this->animation_ability);
    this->delay_ability = this->DELAY_ABILITY;
  }
  else {
    set_friend_animation(this, this->animation_passive);
  }
  this->is_passive = !this->is_passive;
}

/* GLOBAL */
void update_friend_animation(Friend *this, Row *row) {
  int i;
  bool enemy_in_range = false;
  if (this->ability == DEFENSE || this->ability == ATTACK) {
    for (i=0; i<row->nb_enemies; i++) {
      if (row->enemies[i].posX < this->posX) {
	continue;
      }
      if (row->enemies[i].posX < this->posX + this->range) {
	enemy_in_range = true;
	break;
      }
    }
    if (enemy_in_range == this->is_passive) {
      switch_friend_behavior(this);
    }
  }

  if (this->ability == MONEY || !this->is_passive) {
    this->DELAY_ABILITY--;
    if (this->DELAY_ABILITY == 0) {
      use_friend_ability(this, row);
    }
  }
  MLV_update_animation_player(this->animation);
}
