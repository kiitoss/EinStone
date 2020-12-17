#include "../menuHeader.h"
#include "../makhead.h"

/* GLOBAL */
Event_Manager get_event() {
  Event_Manager em;
  em.event = MLV_get_event(&em.touch, NULL, NULL, &em.text_input, &em.input_box, &em.mouseX, &em.mouseY, NULL, &em.btn_state);
  return em;
}

/* GLOBAL */
void draw_main_page(mainPage *mp) {
  MLV_clear_window(MLV_COLOR_BLACK);
  draw_button(&mp->newgame_btn);
  draw_button(&mp->resume_btn);
  draw_button(&mp->score_btn);
  draw_button(&mp->quit_btn);
  MLV_update_window();
}
