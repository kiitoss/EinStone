#include "../game_header.h"






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
void remove_enemy_from_row(Row *this, int index_enemy, Sound_Manager *SM, int *p1_score) {
  int i;
  *p1_score += this->enemies[index_enemy].score;
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
void update_all_collisions_in_row(Row *this, Sound_Manager *SM, int *p1_score) {
  int i = 0;
  int j;
  Shot *s;
  Enemy *e;
  
  while (i<this->nb_shots) {
    s = &this->shots[i];
    for (j=0; j<this->nb_enemies; j++) {
      e = &this->enemies[j];
      if (s->posX + this->rectsize/2 >= e->posX + e->padding && s->posX <= e->posX + e->padding + this->rectsize) {
	e->life -= s->attack;
	remove_shot_from_row(this, i);
	if (e->life <= 0) {
	  remove_enemy_from_row(this, j, SM, p1_score);
	}
	break;
      }
    }
    i++;
  }
}





/* Supprime tous les ennemies d'une ligne. */
void remove_all_enemies_in_row(Row *this, Player_1 *p1) {
  this->nb_enemies = 0;
  p1->life--;
  set_player_life_str(p1->life, p1->life_str);
  if (p1->life == 0) {
    printf("You loose\n");
  }
}





/* Met à jour tous les alliés d'une ligne. */
void update_all_friends_in_row(Row *this, Sound_Manager *SM, int *p1_score) {
  int i;
  for (i=0; i<NB_COLUMNS;i++) {
    if (!is_friend(&this->friends[i])) {
      continue;
    }
    update_friend(&this->friends[i], this, SM, p1_score);
  }
}





/* Met à jour tous les ennemies d'une ligne. */
void update_all_enemies_in_row(Row *this, Player_1 *p1, Sound_Manager *SM) {
  int i=0;
  while (i<this->nb_enemies) {
    update_enemy(&this->enemies[i], this, SM);
    if (this->enemies[i].posX <= -this->rectsize) {
      remove_all_enemies_in_row(this, p1);
    }
    i++;
  }
}





/* Met à jour tous les tirs d'une ligne. */
void update_all_shots_in_row(Row *this, Game_Manager *GM) {
  int i=0;
  while (i<this->nb_shots) {
    move_shot(&this->shots[i]);
    if (this->shots[i].posX >= GM->window.field.width) {
      remove_shot_from_row(this, i);
      i--;
    }
    i++;
  }
}





/* Met à jour toutes les pièces d'or d'une ligne. */
void update_all_golds_in_row(Row *this) {
  int i=0;
  while (i<this->nb_golds) {
    update_gold(&this->golds[i]);
    if (this->golds[i].time_left <= 0) {
      remove_gold_from_row(this, i);
      i--;
    }
    i++;
  }
}





/* Met à jour une ligne du terrain. */
/* GLOBAL */
void update_row(Row *this, Game_Manager *GM, Sound_Manager *SM) {
  update_all_friends_in_row(this, SM, &GM->p1.score);
  update_all_enemies_in_row(this, &GM->p1, SM);
  update_all_shots_in_row(this, GM);
  
  update_all_collisions_in_row(this, SM, &GM->p1.score);
  update_all_golds_in_row(this);
}
