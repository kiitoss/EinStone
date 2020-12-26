#include "../../mainHeader.h"
#include "../makhead.h"





/* Supprime un allié d'une ligne. */
/* GLOBAL */
void remove_friend_from_row(Friend *f) {
  f->id_friend = -1;
}





/* Supprime une pièce d'or d'une ligne. */
/* GLOBAL */
void remove_gold_from_row(Row *this, int index_gold) {
  int i;
  for (i=index_gold; i<this->nb_golds - 1; i++) {
    this->golds[i] = this->golds[i+1];
  }
  this->nb_golds--;
}





/* Supprime un tir allié d'une ligne. */
/* GLOBAL */
void remove_shot_from_row(Row *this, int index_shot) {
  int i;
  for (i=index_shot; i<this->nb_shots - 1; i++) {
    this->shots[i] = this->shots[i+1];
  }
  this->nb_shots--;
}





/* Supprime un ennemie d'une ligne. */
/* GLOBAL */
void remove_enemy_from_row(Row *this, int index_enemy, Sound_Manager *SM) {
  int i;
  play_sound(SM, &SM->big_monster_roar);
  for (i=index_enemy; i<this->nb_enemies - 1; i++) {
    this->enemies[i] = this->enemies[i+1];
  }
  this->nb_enemies--;
}





/* Créé un nouvel allié sur une ligne. */
/* GLOBAL */
void add_friend_in_row(Row *this, Friend_Spawner *spawner, int gridX, int gridY) {
  this->friends[gridX] = get_new_friend(spawner,
					gridX * this->rectsize,
					gridY * this->rectsize);
}





/* Créé un nouvel ennemie sur une ligne. */
/* GLOBAL */
void add_enemy_in_row(Row *this, Enemy_Spawner *spawner, int posX, int posY) {
  this->enemies[this->nb_enemies++] = get_new_enemy(spawner,
						    posX,
						    posY);
}





/* Vérifie les collisions entre tirs alliés et ennemies. */
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





/* Supprime tous les ennemies d'une ligne. */
void remove_all_enemies_in_row(Row *r, Player_1 *p1) {
  r->nb_enemies = 0;
  p1->life--;
  set_player_life_str(p1->life, p1->life_str);
  if (p1->life == 0) {
    printf("You loose\n");
  }
}





/* Met à jour tous les alliés d'une ligne. */
void update_friends(Row *r, Sound_Manager *SM) {
  int i;
  for (i=0; i<NB_COLUMNS;i++) {
    if (!is_friend(&r->friends[i])) {
      continue;
    }
    update_friend_animation(&r->friends[i], r, SM);
  }
}





/* Met à jour tous les ennemies d'une ligne. */
void update_enemies(Row *r, Player_1 *p1, Sound_Manager *SM) {
  int i=0;
  while (i<r->nb_enemies) {
    update_enemy_animation(&r->enemies[i], r, SM);
    move_enemy(&r->enemies[i]);
    if (r->enemies[i].posX <= -r->rectsize) {
      remove_all_enemies_in_row(r, p1);
    }
    i++;
  }
}





/* Met à jour tous les tirs d'une ligne. */
void update_shots(Row *r, Game_Manager *GM) {
  int i=0;
  while (i<r->nb_shots) {
    update_shot(&r->shots[i]);
    if (r->shots[i].posX >= GM->window.field.width) {
      remove_shot_from_row(r, i);
      i--;
    }
    i++;
  }
}





/* Met à jour toutes les pièces d'or d'une ligne. */
void update_golds(Row *r) {
  int i=0;
  while (i<r->nb_golds) {
    update_gold(&r->golds[i]);
    if (r->golds[i].time_left <= 0) {
      remove_gold_from_row(r, i);
      i--;
    }
    i++;
  }
}





/* Met à jour les lignes du terrain. */
/* GLOBAL */
void update_rows(Game_Manager *GM, Sound_Manager *SM) {
  int i;
  Row *r;
  for (i=0; i<NB_ROWS; i++) {
    r = &GM->rows[i];
    update_friends(r, SM);
    update_enemies(r, &GM->p1, SM);
    update_shots(r, GM);
    
    update_collision(r, SM);
    update_golds(r);
  }
}
