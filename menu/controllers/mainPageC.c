#include "../menuHeader.h"
#include "../makhead.h"

void update_hover_btn(mainPage *mp, int posX, int posY) {
  Button *hover_btn = get_main_page_hover_btn(mp, posX, posY);
  if (hover_btn != NULL && mp->hover_btn != hover_btn) {
    if (mp->hover_btn != NULL) {
      unset_hover_btn(mp->hover_btn);
    }
    set_hover_btn(hover_btn);
    mp->hover_btn = hover_btn;
    draw_main_page(mp);
  }
}

void update_main_page(mainPage *mp) {
  Event_Manager em;
  draw_main_page(mp);
  em = get_event();
  while (em.event != MLV_MOUSE_MOTION && (em.event != MLV_MOUSE_BUTTON || em.btn_state != MLV_PRESSED)) {
    em = get_event();
  }
  if (em.event == MLV_MOUSE_BUTTON) {
    printf("clique\n");
  }
  else {
    update_hover_btn(mp, em.mouseX, em.mouseY);
  }
  update_main_page(mp);
}

/* GLOBAL */
void launch_main_page(int width, int height) {
  mainPage mp;
  Geometry g;
  int margin = 5;
  int row_height = height / 6 - margin;

  mp.hover_btn = NULL;
  
  g.width = width;
  g.height = row_height;
  g.posX = 0;
  g.posY = margin;

  mp.width = width;
  mp.height = height;
  
  /* mp.title_lbl = ; */
  g.posY += row_height*2 + margin;
  
  mp.newgame_btn = get_new_button(g, "New Game", MLV_COLOR_RED, "res/font/Amatic-Bold.ttf", NEWGAME);
  g.posY += row_height + margin;
  
  mp.resume_btn = get_new_button(g, "Resume", MLV_COLOR_RED, "res/font/Amatic-Bold.ttf", RESUME);
  g.posY += row_height + margin;
  
  mp.score_btn = get_new_button(g, "Score", MLV_COLOR_RED, "res/font/Amatic-Bold.ttf", SCORE);
  g.posY += row_height + margin;
  
  mp.quit_btn = get_new_button(g, "Quit", MLV_COLOR_RED, "res/font/Amatic-Bold.ttf", BACK);

  /* draw_main_page(&mp); */

  update_main_page(&mp);
}

int main(int argc, char *argv[]) {
  int width, height;
  width = 700;
  height = 700;
  MLV_create_window("TEST", "TEST", width, height);
  launch_main_page(width, height);
  MLV_wait_seconds(2);
  MLV_free_window();
  exit(0);
}
