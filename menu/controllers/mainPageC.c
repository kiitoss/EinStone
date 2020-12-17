#include "../menuHeader.h"
#include "../makhead.h"

void update_main_page(mainPage *mp) {
  /* draw_main_page(&mp); */
}

/* GLOBAL */
void launch_main_page(int width, int height) {
  mainPage mp;
  Geometry g;
  int margin = 5;
  int row_height = height / 6 - margin;
  
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
