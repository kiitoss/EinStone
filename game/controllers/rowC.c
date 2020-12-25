#include "../../mainHeader.h"
#include "../makhead.h"


/* GLOBAL */
void remove_friend_from_row(Friend *f) {
  f->id_friend = -1;
}

/* GLOBAL */
void remove_gold_from_row(Row *this, int index_gold) {
  int i;
  for (i=index_gold; i<this->nb_golds - 1; i++) {
    this->golds[i] = this->golds[i+1];
  }
  this->nb_golds--;
}

/* GLOBAL */
void remove_shot_from_row(Row *this, int index_shot) {
  int i;
  for (i=index_shot; i<this->nb_shots - 1; i++) {
    this->shots[i] = this->shots[i+1];
  }
  this->nb_shots--;
}

/* GLOBAL */
void remove_enemy_from_row(Row *this, int index_enemy, Sound_Manager *SM) {
  int i;
  play_sound(SM, &SM->big_monster_roar);
  for (i=index_enemy; i<this->nb_enemies - 1; i++) {
    this->enemies[i] = this->enemies[i+1];
  }
  this->nb_enemies--;
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
  this->time_left -= DELAY_REFRESH;
}

void update_shot(Shot *this) {
  this->posX += this->speed;
}

void update_collision(Row *r, Sound_Manager *SM) {
  int i = 0;
  int j;
  Shot *s;
  Enemy *e;
  while (i<r->nb_shots) {
    s = &r->shots[i];
    for (j=0; j<r->nb_enemies; j++) {
      e = &r->enemies[j];
      if (s->posX + r->rectsize/2 >= e->posX + e->padding && s->posX <= e->posX + e->padding + r->rectsize) {
	e->life -= s->attack;
	remove_shot_from_row(r, i);
	if (e->life <= 0) {
	  remove_enemy_from_row(r, j, SM);
	}
	break;
      }
    }
    i++;
  }
}

void remove_all_enemies_in_row(Row *r, Player_1 *p1) {
  r->nb_enemies = 0;
  p1->life--;
  set_player_life_str(p1->life, p1->life_str);
  if (p1->life == 0) {
    printf("You loose\n");
  }
}

/* GLOBAL */
void update_rows(Game_Manager *GM, Sound_Manager *SM) {
  int i, j;
  Row *r;
  for (i=0; i<NB_ROWS; i++) {
    r = &GM->rows[i];
    for (j=0; j<NB_COLUMNS; j++) {
      if (r->friends[j].id_friend == -1) {
	continue;
      }
      update_friend_animation(&r->friends[j], r, SM);
    }
    j = 0;
    while (j<r->nb_enemies) {
      update_enemy_animation(&r->enemies[j], r, SM);
      move_enemy(&r->enemies[j]);
      if (r->enemies[j].posX <= -GM->window.rectsize) {
	remove_all_enemies_in_row(r, &GM->p1);
      }
      j++;
    }
    j = 0;
    while (j<r->nb_shots) {
      update_shot(&r->shots[j]);
      if (r->shots[j].posX >= GM->window.field.width) {
	remove_shot_from_row(r, j);
	j--;
      }
      j++;
    }
    update_collision(r, SM);
    j = 0;
    while (j<r->nb_golds) {
      update_gold(&r->golds[j]);
      if (r->golds[j].time_left <= 0) {
	remove_gold_from_row(r, j);
	j--;
      }
      j++;
    }
  }
}
