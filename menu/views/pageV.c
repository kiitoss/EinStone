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
  draw_label(&mp->title_lbl);
  draw_button(&mp->newgame_btn);
  draw_button(&mp->resume_btn);
  draw_button(&mp->score_btn);
  draw_button(&mp->quit_btn);
  MLV_update_window();
}

/* GLOBAL */
void draw_newgame_page(newgamePage *ngp) {
  MLV_clear_window(MLV_COLOR_BLACK);

  draw_label(&ngp->title_lbl);
  draw_button(&ngp->solo_btn);
  draw_button(&ngp->multi_btn);
  draw_button(&ngp->easy_btn);
  draw_button(&ngp->medium_btn);
  draw_button(&ngp->hard_btn);
  draw_button(&ngp->back_btn);
  draw_button(&ngp->launch_btn);

  draw_input_or_label(&ngp->p1_input, &ngp->p1_lbl);
  draw_input_or_label(&ngp->p2_input, &ngp->p2_lbl);
  
  MLV_update_window();
}
