#include "../game_header.h"





/* Retourne un nouvel allié. */
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





/* Retourne vrai si le paramètre est un allié. */
/* GLOBAL */
bool is_friend(Friend *this) {
  return this->id_friend != -1;
}





/* Affecte une animation à un allié. */
/* GLOBAL */
void set_friend_animation(Friend *this, MLV_Animation_player *animation) {
  this->animation = animation;
  MLV_play_animation_player(this->animation);
}





/* Attaque tous les ennemies dans la range de l'allié. */
void attack_all_enemies_in_range(Friend *this, Row *row, Sound_Manager *SM, int *p1_score) {
  int i = 0;
  Enemy *e;
  
  play_sound(SM, &SM->spear);
  
  while (i<row->nb_enemies) {
    e = &row->enemies[i];
    if (e->posX + e->padding < this->posX + this->range + row->rectsize && e->posX + e->padding + row->rectsize > this->posX) {
      e->life -= this->attack;
      if (e->life <= 0) {
	remove_enemy_from_row(row, i, SM, p1_score);
	i--;
      }
    }
    i++;
  }
}





/* Change le comportement de l'allié. */
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





/* Utilise le pouvoir de l'allié */
void use_friend_ability(Friend *this, Row *row, Sound_Manager *SM, int *p1_score) {
  switch (this->ability) {
  case DEFENSE:
    attack_all_enemies_in_range(this, row, SM, p1_score);
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





/* Met à jour l'allié. */
/* GLOBAL */
void update_friend(Friend *this, Row *row, Sound_Manager *SM, int *p1_score) {
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

    if (enemy_in_range ^ !this->is_passive) {
      switch_friend_behavior(this);
    }
  }

  if (this->ability == MONEY || !this->is_passive) {
    this->delay_ability -= DELAY_REFRESH;
    if (this->delay_ability <= 0) {
      use_friend_ability(this, row, SM, p1_score);
    }
  }
  
  MLV_update_animation_player(this->animation);
}



/* GLOBAL */
void reset_friend_animations(Friend *this, Friend_Spawner *spawner) {
  this->animation_passive = MLV_create_animation_player(spawner->animation_passive);
  this->animation_ability = MLV_create_animation_player(spawner->animation_ability);
  if (this->is_passive) {
    set_friend_animation(this, this->animation_passive);
  }
  else {
    set_friend_animation(this, this->animation_ability);
  }
}
			  
