#include "../../mainHeader.h"
#include "../makhead.h"

void attack_all_enemies_in_range(Friend *this, Row *row, Sound_Manager *SM) {
  int i = 0;
  Enemy *e;
  play_sound(SM, &SM->spear);
  while (i<row->nb_enemies) {
    e = &row->enemies[i];
    if (e->posX + e->padding < this->posX + this->range + row->rectsize && e->posX + e->padding + row->rectsize > this->posX) {
      e->life -= this->attack;
      if (e->life <= 0) {
	remove_enemy_from_row(row, i, SM);
	i--;
      }
    }
    i++;
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

void use_friend_ability(Friend *this, Row *row, Sound_Manager *SM) {
  switch (this->ability) {
  case DEFENSE:
    attack_all_enemies_in_range(this, row, SM);
    this->delay_ability = this->DELAY_ABILITY;
    break;
  case ATTACK:
    create_new_shot(row, this->posX/row->rectsize, this->posY/row->rectsize, this->attack, SM);
    this->delay_ability = this->DELAY_ABILITY;
    break;
  case MONEY:
    switch_friend_behavior(this);
    if (!this->is_passive) {
      create_new_gold(row, this->posX/row->rectsize, this->posY/row->rectsize, SM);
      this->delay_ability = 2000;
    }
    else {
      this->delay_ability = this->DELAY_ABILITY;
    }
    break;
  default:
    break;
  }
}

/* GLOBAL */
void update_friend_animation(Friend *this, Row *row, Sound_Manager *SM) {
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
    this->delay_ability -= DELAY_REFRESH;
    if (this->delay_ability <= 0) {
      use_friend_ability(this, row, SM);
    }
  }
  MLV_update_animation_player(this->animation);
}
