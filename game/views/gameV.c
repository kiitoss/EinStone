#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
void draw_game(Game_Manager *GM, Texture_Manager *TM) {
  draw_window(GM, TM);
  MLV_update_window();
}

/* GLOBAL */
Event_Manager get_game_event() {
  Event_Manager em;
  em.event = MLV_get_event(&em.touch, NULL, NULL, NULL, NULL, &em.mouseX, &em.mouseY, NULL, &em.btn_state);
  return em;
}
