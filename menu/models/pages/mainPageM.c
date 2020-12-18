#include "../../menuHeader.h"
#include "../../makhead.h"

/* GLOBAL */
mainPage init_main_page(int width, int height) {
  mainPage mp;
  Geometry g;
  int margin = 5;
  int row_height = height / 6 - margin;
  char *font_path = "res/font/Amatic-Bold.ttf";

  mp.hover_btn = NULL;
  
  g.width = width;
  g.height = row_height;
  g.posX = 0;
  g.posY = margin;

  mp.width = width;
  mp.height = height;
  
  /* mp.title_lbl = ; */
  g.posY += row_height*2 + margin;
  
  mp.newgame_btn = get_new_button(g, "New Game", MLV_COLOR_RED, font_path, NEWGAME);
  g.posY += row_height + margin;
  
  mp.resume_btn = get_new_button(g, "Resume", MLV_COLOR_RED, font_path, RESUME);
  g.posY += row_height + margin;
  
  mp.score_btn = get_new_button(g, "Score", MLV_COLOR_RED, font_path, SCORE);
  g.posY += row_height + margin;
  
  mp.quit_btn = get_new_button(g, "Quit", MLV_COLOR_RED, font_path, BACK);

  return mp;
}

/* GLOBAL */
Button *get_main_page_hover_btn(mainPage *this, int posX, int posY) {
  Button *hover_btn = NULL;
  if (is_btn_hover(&this->newgame_btn, posX, posY)) {
    hover_btn = &this->newgame_btn;
  }
  else if (is_btn_hover(&this->resume_btn, posX, posY)) {
    hover_btn = &this->resume_btn;
  }
  else if (is_btn_hover(&this->score_btn, posX, posY)) {
    hover_btn = &this->score_btn;
  }
  else if (is_btn_hover(&this->quit_btn, posX, posY)) {
    hover_btn = &this->quit_btn;
  }
  return hover_btn;
}
