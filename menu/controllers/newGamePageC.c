#include "../menuHeader.h"
#include "../makhead.h"

void update_newgame_page(newgamePage *ngp);

static void select_hover_btn(newgamePage *ngp) {
  switch (ngp->hover_btn->value) {
  case BACK:
    launch_main_page(ngp->width, ngp->height);
    break;
  case SOLO:
    set_gamemode(ngp, SOLO);
    break;
  case MULTI:
    set_gamemode(ngp, MULTI);
    break;
  case EASY:
    set_difficulty(ngp, EASY);
    break;
  case MEDIUM:
    set_difficulty(ngp, MEDIUM);
    break;
  case HARD:
    set_difficulty(ngp, HARD);
    break;
  default:
    break;
  }
}

static void update_hover_btn(newgamePage *ngp, int posX, int posY) {
  Button *hover_btn = get_newgame_page_hover_btn(ngp, posX, posY);
  if (ngp->hover_btn != hover_btn) {
    unset_hover_btn(ngp->hover_btn);
    set_hover_btn(hover_btn);
    ngp->hover_btn = hover_btn;
  }
}

void update_newgame_page(newgamePage *ngp) {
  Event_Manager em;
  int launch_time = MLV_get_time();
  draw_newgame_page(ngp);
  em = get_event();
  while (em.event != MLV_MOUSE_MOTION && (em.event != MLV_MOUSE_BUTTON || em.btn_state != MLV_PRESSED || ngp->hover_btn == NULL) && (em.event != MLV_KEY || em.touch != MLV_KEYBOARD_ESCAPE)) {
    em = get_event();
    if (MLV_get_time() > launch_time + 200) {
      em.event = MLV_NONE;
      break;
    }
  }
  MLV_flush_event_queue();
  if (em.event == MLV_MOUSE_BUTTON && em.btn_state == MLV_PRESSED && ngp->hover_btn != NULL) {
    select_hover_btn(ngp);
    update_newgame_page(ngp);
  }
  else if (em.event == MLV_KEY && em.touch == MLV_KEYBOARD_ESCAPE) {
    launch_main_page(ngp->width, ngp->height);
  }
  else if (em.event == MLV_MOUSE_MOTION) {
    update_hover_btn(ngp, em.mouseX, em.mouseY);
    update_newgame_page(ngp);
  }
  else if (em.event == MLV_NONE) {
    update_newgame_page(ngp);
  }
}

/* GLOBAL */
void launch_newgame_page(int width, int height) {
  newgamePage ngp = init_newgame_page(width, height);
  set_gamemode(&ngp, SOLO);
  set_difficulty(&ngp, MEDIUM);
  draw_newgame_page(&ngp);
  MLV_flush_event_queue();
  update_newgame_page(&ngp);
}
