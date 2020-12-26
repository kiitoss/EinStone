#include "../menuHeader.h"
#include "../makhead.h"


/* GLOBAL */
resumePage init_resume_page(int width, int height, GM_List GM_list) {
  resumePage rp;
  Geometry g;
  int i;
  int margin_title = height/3 * 0.2;
  int title_height = height/3 * 0.8;
  
  int margin_row = 2*height/3 * 0.3/(SAVED_GAMES+1);
  int row_height = 2*height/3 * 0.7/(SAVED_GAMES+1);
  char *font_path = "./resources/font/Amatic-Bold.ttf";

  rp.hover_btn = NULL;
  rp.hover_section = NULL;
  rp.select_section = NULL;
  
  g.width = width/2;
  g.height = title_height;
  g.posX = width/4;
  g.posY = 0;

  rp.width = width;
  rp.height = height;
  
  rp.title_lbl = get_new_label(g, "Ein Stone", MLV_COLOR_RED, font_path);

  g.height = row_height;
  g.posY += title_height + margin_title;
  for (i=0; i<SAVED_GAMES; i++) {
    if (GM_list[i].id == 0) {
      rp.sections[i] = get_new_resumeSection(g, "NULL", "NULL", 0, 0, 0, font_path);
      rp.sections[i].exist = false;
    }
    else {
      rp.sections[i] = get_new_resumeSection(g, GM_list[i].p1.name, GM_list[i].p2.name, GM_list[i].p1.score, GM_list[i].p2.score, GM_list[i].duration, font_path);
    }
    g.posY += row_height + margin_row;
  }

  g.width = width/4;
  g.posX = 0;
  rp.back_btn = get_new_button(g, "Back", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, BACK);
  g.posX = 3*width/4;
  rp.launch_btn = get_new_button(g, "Launch", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, LAUNCH);

  return rp;
}


/* GLOBAL */
Button *get_resume_page_hover_btn(resumePage *this, int posX, int posY) {
  Button *hover_btn = NULL;
  if (is_btn_hover(&this->back_btn, posX, posY)) {
    hover_btn = &this->back_btn;
  }
  else if (is_btn_hover(&this->launch_btn, posX, posY)) {
    hover_btn = &this->launch_btn;
  }
  return hover_btn;
}

/* GLOBAL */
resumeSection *get_resume_page_hover_section(resumePage *this, int posX, int posY) {
  resumeSection *hover_section = NULL;
  int i;
  for (i=0; i<SAVED_GAMES; i++) {
    if (is_resumeSection_hover(&this->sections[i], posX, posY)) {
      hover_section = &this->sections[i];
    }
  }
  return hover_section;
}
