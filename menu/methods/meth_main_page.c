#include "../menu_structures.h"
#include "../menu_functions.h"

/* GLOBAL */
Button *get_main_page_hover_btn(Main_Page *this, int posX, int posY) {
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

/* GLOBAL */
Main_Page init_main_page(int width, int height) {
  Main_Page mp;
  Geometry g;
  int margin_title = height/3 * 0.2;
  int title_height = height/3 * 0.8;
  
  int margin_row = (2*height/3 * 0.2)/4;
  int row_height = (2*height/3 * 0.8)/4;
  char *font_path = "resources/font/Amatic-Bold.ttf";

  mp.hover_btn = NULL;
  
  g.width = width;
  g.height = title_height;
  g.posX = 0;
  g.posY = 0;

  mp.width = width;
  mp.height = height;

  mp.title_lbl = get_new_label(g, "Ein Stone", MLV_COLOR_RED, font_path);

  g.height = row_height;
  g.posY += title_height + margin_title;
  
  mp.newgame_btn = get_new_button(g, "New Game", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, NEWGAME);
  g.posY += row_height + margin_row;
  
  mp.resume_btn = get_new_button(g, "Resume", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, RESUME);
  g.posY += row_height + margin_row;
  
  mp.score_btn = get_new_button(g, "Score", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, SCORE);
  g.posY += row_height + margin_row;
  
  mp.quit_btn = get_new_button(g, "Quit", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, BACK);

  return mp;
}
