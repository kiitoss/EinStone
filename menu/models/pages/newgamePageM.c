#include "../../menuHeader.h"
#include "../../makhead.h"

/* GLOBAL */
newgamePage init_newgame_page(int width, int height) {
  newgamePage ngp;
  Geometry g;
  int margin_title = height/3 * 0.2;
  int title_height = height/3 * 0.8;
  
  int margin_row = 2*height/3 * 0.3/4;
  int row_height = 2*height/3 * 0.7/4;
  char *font_path = "res/font/Amatic-Bold.ttf";

  ngp.hover_btn = NULL;
  
  g.width = width;
  g.height = title_height;
  g.posX = 0;
  g.posY = 0;

  ngp.width = width;
  ngp.height = height;
  
  ngp.title_lbl = get_new_label(g, "Ein Stone", MLV_COLOR_RED, font_path);

  g.height = row_height;
  g.posY += title_height + margin_title;
  g.width = width/4;
  g.posX = width/4;
  ngp.solo_btn = get_new_button(g, "SOLO", MLV_COLOR_RED, font_path, SOLO);
  g.posX += width/4;
  ngp.multi_btn = get_new_button(g, "MULTI", MLV_COLOR_RED, font_path, MULTI);

  g.posY += row_height + margin_row;
  g.width = 3*width/8 - 5;
  g.posX = width/8;
  ngp.p1_input = get_new_input(g, "Joueur 1: ", MLV_COLOR_RED, font_path);
  g.posX += 3*width/8 + 5;
  ngp.p2_input = get_new_input(g, "Joueur 2: ", MLV_COLOR_RED, font_path);
  
  g.posY += row_height + margin_row;
  g.width = width/3;
  g.posX = 0;
  ngp.easy_btn = get_new_button(g, "EASY", MLV_COLOR_RED, font_path, EASY);
  g.posX += width/3;
  ngp.medium_btn = get_new_button(g, "MEDIUM", MLV_COLOR_RED, font_path, MEDIUM);
  g.posX += width/3;
  ngp.hard_btn = get_new_button(g, "HARD", MLV_COLOR_RED, font_path, HARD);
  

  g.posY += row_height + margin_row;
  g.width = width/4;
  g.posX = 0;
  ngp.back_btn = get_new_button(g, "Back", MLV_COLOR_RED, font_path, BACK);
  g.posX = 3*width/4;
  ngp.launch_btn = get_new_button(g, "Launch", MLV_COLOR_RED, font_path, LAUNCH);

  return ngp;
}


/* GLOBAL */
Button *get_newgame_page_hover_btn(newgamePage *this, int posX, int posY) {
  Button *hover_btn = NULL;
  if (is_btn_hover(&this->solo_btn, posX, posY)) {
    hover_btn = &this->solo_btn;
  }
  else if (is_btn_hover(&this->multi_btn, posX, posY)) {
    hover_btn = &this->multi_btn;
  }
  else if (is_btn_hover(&this->easy_btn, posX, posY)) {
    hover_btn = &this->easy_btn;
  }
  else if (is_btn_hover(&this->medium_btn, posX, posY)) {
    hover_btn = &this->medium_btn;
  }
  else if (is_btn_hover(&this->hard_btn, posX, posY)) {
    hover_btn = &this->hard_btn;
  }
  else if (is_btn_hover(&this->back_btn, posX, posY)) {
    hover_btn = &this->back_btn;
  }
  else if (is_btn_hover(&this->launch_btn, posX, posY)) {
    hover_btn = &this->launch_btn;
  }
  return hover_btn;
}
