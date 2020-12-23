#include "../gameHeader.h"
#include "../makhead.h"


/* GLOBAL */
void remove_gold_from_row(Row *this, int index_gold) {
  int i;
  for (i=index_gold; i<this->nb_golds - 1; i++) {
    this->golds[i] = this->golds[i+1];
  }
  this->nb_golds--;
}

/* GLOBAL */
void add_friend_in_row(Row *this, Friend_Spawner *spawner, int gridX, int gridY) {
  this->friends[gridX] = get_new_friend(spawner,
					gridX * this->rectsize,
					gridY * this->rectsize);
}

/* GLOBAL */
void add_enemy_in_row(Row *this, Enemy_Spawner *spawner, int posX, int posY) {
  this->enemies[this->nb_enemies++] = get_new_enemy(spawner,
						    posX,
						    posY);
}

void update_gold(Gold *this) {
  if (this->radius < this->max_radius) {
    this->radius += 10;
  }
  this->time_left--;
}

void update_shot(Shot *this) {
  this->posX += this->speed;
}

/* GLOBAL */
void update_rows(Game_Manager *GM, Texture_Manager *TM) {
  int i, j;
  Row *r;
  for (i=0; i<NB_ROWS; i++) {
    r = &GM->rows[i];
    for (j=0; j<NB_COLUMNS; j++) {
      if (r->friends[j].id_friend == -1) {
	continue;
      }
      update_friend_animation(&r->friends[j], r);
    }
    for (j=0; j<r->nb_enemies; j++) {
      update_enemy_animation(&r->enemies[j], r);
      move_enemy(&r->enemies[j]);
    }
    for (j=0; j<r->nb_golds; j++) {
      update_gold(&r->golds[j]);
    }
    for (j=0; j<r->nb_shots; j++) {
      update_shot(&r->shots[j]);
    }
  }
}
