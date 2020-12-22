#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
void draw_game(Game_Manager *GM, Texture_Manager *TM) {
  int i, j;
  Row r;
  draw_window(GM, TM);
  for (i=0; i<NB_ROWS; i++) {
    r = GM->rows[i];
    for (j=0; j<NB_COLUMNS; j++) {
      if (r.friends[j].id_friend == -1) {
	continue;
      }
      MLV_draw_image_from_animation_player(r.friends[j].animation, 0, r.friends[j].posX + GM->window.field.posX, r.friends[j].posY + GM->window.field.posY);
    }
  }
  MLV_update_window();
}

/* GLOBAL */
Event_Manager get_game_event() {
  Event_Manager em;
  em.event = MLV_get_event(&em.touch, NULL, NULL, NULL, NULL, &em.mouseX, &em.mouseY, NULL, &em.btn_state);
  return em;
}
