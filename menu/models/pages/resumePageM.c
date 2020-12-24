#include "../../menuHeader.h"
#include "../../makhead.h"


/* GLOBAL */
resumePage init_resume_page(int width, int height) {
  resumePage rp;
  Geometry g;
  int i;
  int margin_title = height/3 * 0.2;
  int title_height = height/3 * 0.8;
  
  int margin_row = 2*height/3 * 0.3/6;
  int row_height = 2*height/3 * 0.7/6;
  char *font_path = "./resources/font/Amatic-Bold.ttf";

  rp.hover_btn = NULL;
  rp.hover_section = NULL;
  rp.select_section = NULL;
  
  g.width = width;
  g.height = title_height;
  g.posX = 0;
  g.posY = 0;

  rp.width = width;
  rp.height = height;
  
  rp.title_lbl = get_new_label(g, "Ein Stone", MLV_COLOR_RED, font_path);

  g.height = row_height;
  g.posY += title_height + margin_title;

  for (i=0;i<5;i++) {
    rp.sections[i].section_lbl = get_new_label(g, "Section", MLV_COLOR_RED, font_path);
    g.posY += row_height + margin_row;
  }

  g.width = width/4;
  g.posX = 0;
  rp.back_btn = get_new_button(g, "Back", MLV_COLOR_RED, font_path, BACK);
  g.posX = 3*width/4;
  rp.launch_btn = get_new_button(g, "Launch", MLV_COLOR_RED, font_path, LAUNCH);

  return rp;
}
