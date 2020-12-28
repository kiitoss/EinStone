#include "../menu_structures.h"
#include "../menu_functions.h"

void update_newgame_page(Newgame_Page *ngp);

void prepare_launching(Newgame_Page *ngp) {
  btn_value gamemode, difficulty;
  char *p1_name, *p2_name;
  gamemode = ngp->select_gamemode->value;
  difficulty = (gamemode == SOLO) ? ngp->select_difficulty->value : MEDIUM;
  p1_name = get_input_or_label_value(&ngp->p1_input, &ngp->p1_lbl);
  p2_name = (gamemode == MULTI) ? get_input_or_label_value(&ngp->p2_input, &ngp->p2_lbl) : "IA";

  if (strlen(p1_name) == 0) {
    p1_name = "Joueur 1";
  }
  if (strlen(p2_name) == 0) {
    p2_name = "Joueur 2";
  }
  launch_newgame(gamemode, difficulty, p1_name, p2_name);
}

static void select_hover_btn(Newgame_Page *ngp) {
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
  case LAUNCH:
    prepare_launching(ngp);
  default:
    break;
  }
}

static void update_hover_btn(Newgame_Page *ngp, int posX, int posY) {
  Button *hover_btn = get_newgame_page_hover_btn(ngp, posX, posY);
  if (ngp->hover_btn != hover_btn) {
    unset_hover_btn(ngp->hover_btn);
    set_hover_btn(hover_btn);
    ngp->hover_btn = hover_btn;
  }
}

void update_newgame_page(Newgame_Page *ngp) {
  Event_Manager em;
  int launch_time = MLV_get_time();
  draw_newgame_page(ngp);
  em = get_event();
  while (em.event != MLV_MOUSE_MOTION && (em.event != MLV_MOUSE_BUTTON || em.btn_state != MLV_PRESSED || ngp->hover_btn == NULL) && (em.event != MLV_KEY || em.touch != MLV_KEYBOARD_ESCAPE) && em.event != MLV_INPUT_BOX) {
    em = get_event();
    if (MLV_get_time() > launch_time + 200) {
      em.event = MLV_NONE;
      break;
    }
  }
  MLV_flush_event_queue();
  if (em.event == MLV_MOUSE_BUTTON && em.btn_state == MLV_PRESSED && ngp->hover_btn != NULL) {
    select_hover_btn(ngp);
    if (ngp->hover_btn->value != BACK) {
      update_newgame_page(ngp);
    }
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
  else if (em.event == MLV_INPUT_BOX) {
    set_player_name(ngp, em.input_box, em.text_input);
    update_newgame_page(ngp);
  }
}

/* GLOBAL */
void launch_newgame_page(int width, int height) {
  Newgame_Page ngp = init_newgame_page(width, height);
  set_gamemode(&ngp, SOLO);
  set_difficulty(&ngp, MEDIUM);
  set_hidden_lbl(&ngp.p1_lbl);
  set_hidden_lbl(&ngp.p2_lbl);
  draw_newgame_page(&ngp);
  MLV_flush_event_queue();
  update_newgame_page(&ngp);
}
