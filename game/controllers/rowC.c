#include "../gameHeader.h"
#include "../makhead.h"

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
      MLV_update_animation_player(r->friends[j].animation);
    }
    for (j=0; j<r->nb_enemies; j++) {
      MLV_update_animation_player(r->enemies[j].animation);
      r->enemies[j].posX -= r->enemies[j].speed;
    }
  }
}
