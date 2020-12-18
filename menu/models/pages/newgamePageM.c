#include "../../menuHeader.h"
#include "../../makhead.h"

/* GLOBAL */
newgamePage init_newgame_page(int width, int height) {
  newgamePage ngp;
  Geometry g;
  int margin = 5;
  int row_height = height / 6 - margin;
  char *font_path = "res/font/Amatic-Bold.ttf";

  ngp.hover_btn = NULL;
  
  g.width = width;
  g.height = row_height;
  g.posX = 0;
  g.posY = margin;

  ngp.width = width;
  ngp.height = height;
  
  /* ngp.title_lbl = ; */
  
  g.posY += row_height*2 + margin;
  g.width = width/4;
  g.posX = width/4;
  ngp.solo_btn = get_new_button(g, "SOLO", MLV_COLOR_RED, font_path, SOLO);
  g.posX += width/4;
  ngp.multi_btn = get_new_button(g, "MULTI", MLV_COLOR_RED, font_path, MULTI);

  g.posY += row_height + margin;
  /* ngp.p1_input = ; */
  
  g.posY += row_height + margin;
  g.width = width/3;
  g.posX = 0;
  ngp.easy_btn = get_new_button(g, "EASY", MLV_COLOR_RED, font_path, EASY);
  g.posX += width/3;
  ngp.medium_btn = get_new_button(g, "MEDIUM", MLV_COLOR_RED, font_path, MEDIUM);
  g.posX += width/3;
  ngp.hard_btn = get_new_button(g, "HARD", MLV_COLOR_RED, font_path, HARD);
  

  g.posY += row_height + margin;
  g.width = width/4;
  g.posX = 0;
  ngp.back_btn = get_new_button(g, "Back", MLV_COLOR_RED, font_path, BACK);
  g.posX = 3*width/4 - width/25;
  ngp.launch_btn = get_new_button(g, "Launch", MLV_COLOR_RED, font_path, LAUNCH);

  return ngp;
}
