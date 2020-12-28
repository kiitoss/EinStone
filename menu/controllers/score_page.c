#include "../menu_structures.h"
#include "../menu_functions.h"


static void update_hover_btn(Score_Page *sp, int posX, int posY) {
  Button *hover_btn = get_score_page_hover_btn(sp, posX, posY);
  if (sp->hover_btn != hover_btn) {
    unset_hover_btn(sp->hover_btn);
    set_hover_btn(hover_btn);
    sp->hover_btn = hover_btn;
  }
}


void update_score_page(Score_Page *sp) {
  Event_Manager em;
  draw_score_page(sp);
  em = get_event();
  while (em.event != MLV_MOUSE_MOTION && (em.event != MLV_MOUSE_BUTTON || sp->hover_btn == NULL) && (em.event != MLV_KEY || em.touch != MLV_KEYBOARD_ESCAPE)) {
    em = get_event();
  }
  MLV_flush_event_queue();
  if (em.event == MLV_MOUSE_MOTION) {
    update_hover_btn(sp, em.mouseX, em.mouseY);
    update_score_page(sp);
  }
  else if ((em.event != MLV_KEY || em.touch != MLV_KEYBOARD_ESCAPE) && (em.event != MLV_MOUSE_BUTTON || sp->hover_btn == NULL)) {
    update_score_page(sp);
  }
  else {
    launch_main_page(sp->width, sp->height);
  }
}

/* GLOBAL */
void launch_score_page(int width, int height) {
  GM_list_scores GMS;
  Score_Page sp;

  set_GMS(GMS);
  
  sp = init_score_page(width, height, GMS);
  draw_score_page(&sp);
  MLV_flush_event_queue();
  update_score_page(&sp);
}
