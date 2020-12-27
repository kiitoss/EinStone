#include "../menuHeader.h"
#include "../makhead.h"

static void update_hover_btn(mainPage *mp, int posX, int posY) {
  Button *hover_btn = get_main_page_hover_btn(mp, posX, posY);
  if (mp->hover_btn != hover_btn) {
    unset_hover_btn(mp->hover_btn);
    set_hover_btn(hover_btn);
    mp->hover_btn = hover_btn;
  }
}

void change_page(mainPage *mp) {
  switch (mp->hover_btn->value) {
  case NEWGAME:
    launch_newgame_page(mp->width, mp->height);
    break;
  case RESUME:
    launch_resume_page(mp->width, mp->height);
    break;
  case SCORE:
    launch_score_page(mp->width, mp->height);
    break;
  default:
    break;
  } 
}

void update_main_page(mainPage *mp) {
  Event_Manager em;
  draw_main_page(mp);
  em = get_event();
  while (em.event != MLV_MOUSE_MOTION && (em.event != MLV_MOUSE_BUTTON || mp->hover_btn == NULL) && (em.event != MLV_KEY || em.touch != MLV_KEYBOARD_ESCAPE)) {
    em = get_event();
  }
  MLV_flush_event_queue();
  if (em.event == MLV_MOUSE_BUTTON && mp->hover_btn != NULL) {
    change_page(mp);
  }
  else if (em.event == MLV_KEY && em.touch == MLV_KEYBOARD_ESCAPE) {
    return;
  }
  else if (em.event == MLV_MOUSE_MOTION) {
    update_hover_btn(mp, em.mouseX, em.mouseY);
    update_main_page(mp);
  }
}

/* GLOBAL */
void launch_main_page(int width, int height) {
  mainPage mp = init_main_page(width, height);
  draw_main_page(&mp);
  MLV_flush_event_queue();
  update_main_page(&mp);
}
