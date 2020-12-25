#include "../../mainHeader.h"
#include "../makhead.h"





/* Attaque l'allié le plus proche de l'ennemie. */
void attack_friend_in_front(Enemy *this, Row *row, int gridY_friend, Sound_Manager *SM) {
  Friend *f = &row->friends[gridY_friend];
  
  play_sound(SM, &SM->punch);
  
  f->life -= this->attack;
  if (f->life <= 0) {
    remove_friend_from_row(f);
  }
}





/* Change le comportement de l'ennemie. */
void switch_enemy_behavior(Enemy *this) {
  if (this->is_walking) {
    set_enemy_animation(this, this->animation_attack);
  }
  else {
    set_enemy_animation(this, this->animation_walking);
  }
  this->is_walking = !this->is_walking;
}





/* Met à jour l'ennemie. */
/* GLOBAL */
void update_enemy_animation(Enemy *this, Row *row, Sound_Manager *SM) {
  int gridY_far, gridY_close, i, gridY_friend = 0;
  bool friend_in_range = false;
  
  gridY_far = (this->posX + this->padding - this->range) / row->rectsize;
  gridY_far = (gridY_far < 0) ? 0 : gridY_far;
  
  gridY_close = (this->posX + this->padding) / row->rectsize - 1;
  
  for (i=gridY_close; i >= gridY_far; i--) {
    if (is_friend(&row->friends[i])) {
      friend_in_range = true;
      gridY_friend = i;
      break;
    }
  }

  
  if (friend_in_range ^ !this->is_walking) {
    switch_enemy_behavior(this);
  }

  
  if (!this->is_walking) {
    this->delay_attack -= DELAY_REFRESH;
    if (this->delay_attack <= 0) {
      attack_friend_in_front(this, row, gridY_friend, SM);
      this->delay_attack = this->DELAY_ATTACK;
    }
  }

  
  MLV_update_animation_player(this->animation);
}
