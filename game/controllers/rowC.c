#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
void update_rows(Game_Manager *GM, Texture_Manager *TM) {
  int i, j;
  Row r;
  for (i=0; i<NB_ROWS; i++) {
    r = GM->rows[i];
    for (j=0; j<NB_COLUMNS; j++) {
      if (r.friends[j].id_friend == -1) {
	continue;
      }
      MLV_update_animation_player(r.friends[j].animation);
    }
  }
}
