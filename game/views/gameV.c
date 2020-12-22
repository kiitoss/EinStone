#include "../gameHeader.h"
#include "../makhead.h"

void draw_friend(Friend *f, Window *window) {
  MLV_draw_image_from_animation_player(f->animation, 0, f->posX + window->field.posX, f->posY + window->field.posY);
}

void draw_enemy(Enemy *e, Window *window) {
  MLV_draw_image_from_animation_player(e->animation, 0, e->posX + window->field.posX, e->posY + window->field.posY);
}

void draw_row(Row *r, Window *window) {
  int i;
  for (i=0; i<NB_COLUMNS; i++) {
    if (r->friends[i].id_friend == -1) {
      continue;
    }
    draw_friend(&r->friends[i], window);
  }
  for (i=0; i<r->nb_enemies; i++) {
    draw_enemy(&r->enemies[i], window);
  }
}

/* GLOBAL */
void draw_game(Game_Manager *GM, Texture_Manager *TM) {
  int i;
  draw_window(GM, TM);
  for (i=0; i<NB_ROWS; i++) {
    draw_row(&GM->rows[i], &GM->window);
  }
  MLV_update_window();
}

/* GLOBAL */
Event_Manager get_game_event() {
  Event_Manager em;
  em.event = MLV_get_event(&em.touch, NULL, NULL, NULL, NULL, &em.mouseX, &em.mouseY, NULL, &em.btn_state);
  return em;
}
