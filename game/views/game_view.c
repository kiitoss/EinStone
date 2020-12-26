#include "../../mainHeader.h"
#include "../makhead.h"

void draw_shot(Shot *this, MLV_Image *shot_img, Window *window) {
  MLV_draw_image(shot_img, this->posX + window->field.posX, this->posY + window->field.posY);
}

void draw_gold(Gold *this, MLV_Image *gold_img, Window *window) {
  MLV_Image *img = MLV_copy_image(gold_img);
  set_img_size(img, this->radius, this->radius);
  MLV_draw_image(img, this->centerX - this->radius/2 + window->field.posX, this->centerY - this->radius/2 + window->field.posY);
}

void draw_friend(Friend *f, Window *window) {
  MLV_draw_image_from_animation_player(f->animation, 0, f->posX + window->field.posX, f->posY + window->field.posY);
}

void draw_enemy(Enemy *e, Window *window) {
  MLV_draw_image_from_animation_player(e->animation, 0, e->posX + window->field.posX, e->posY + window->field.posY);
}

void draw_row(Row *r, Window *window, Texture_Manager *TM) {
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
  for (i=0; i<r->nb_golds; i++) {
    draw_gold(&r->golds[i], TM->gold_img, window);
  }
  for (i=0; i<r->nb_shots; i++) {
    draw_shot(&r->shots[i], TM->shot_img, window);
  }
}

/* GLOBAL */
void draw_game(Game_Manager *GM, Texture_Manager *TM, int time) {
  int i;
  draw_window(GM, TM);
  for (i=0; i<NB_ROWS; i++) {
    draw_row(&GM->rows[i], &GM->window, TM);
  }
  draw_time(GM->duration + time, &GM->window);
  MLV_update_window();
}

/* GLOBAL */
Event_Manager get_game_event() {
  Event_Manager em;
  em.event = MLV_get_event(&em.touch, NULL, NULL, NULL, NULL, &em.mouseX, &em.mouseY, NULL, &em.btn_state);
  return em;
}