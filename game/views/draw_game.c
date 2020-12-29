#include "../../headers/global_header.h"



/* Dessine la fenêtre et le plateau de jeu, ainsi que les objets. */
void draw_game(Game_Manager *GM, Texture_Manager *TM, int time) {
  int i;
  draw_window(GM, TM);
  for (i=0; i<NB_ROWS; i++) {
    draw_row(&GM->rows[i], &GM->window, TM);
  }
  draw_time(GM->duration + time, &GM->window);
  MLV_update_window();
}



/* Recupere et renvoie l'evenemnt de l'utilisateur. */
Event_Manager get_game_event() {
  Event_Manager em;
  em.event = MLV_get_event(&em.touch, NULL, NULL, NULL, NULL, &em.mouseX, &em.mouseY, NULL, &em.btn_state);
  return em;
}
