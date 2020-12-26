#include "GUI_header.h"


/* GLOBAL */
void draw_resume_section(resumeSection *this) {
  MLV_Color border_color = MLV_rgba(0,0,0,0);
  if (!this->exist) {return;}
  if (this->is_select || this->is_hover) {
    if (this->is_select) {
      border_color = MLV_COLOR_GREEN;
    }
    else {
      border_color = MLV_COLOR_ORANGE;
    }
  }
  MLV_draw_rectangle(this->posX, this->posY, this->width, this->height, border_color);
  draw_label(&this->p1_name_lbl);
  draw_label(&this->p1_score_lbl);
  draw_label(&this->time_lbl);
  draw_label(&this->p2_score_lbl);
  draw_label(&this->p2_name_lbl);
}

/* GLOBAL */
bool is_resumeSection_hover(resumeSection *this, int posX, int posY) {
  if (this != NULL && this->exist && posX >= this->posX && posX <= this->posX + this->width && posY >= this->posY && posY <= this->posY + this->height) {
    return true;
  }
  return false;
}



/* GLOBAL */
resumeSection get_new_resumeSection(Geometry container, char p1_name[21], char p2_name[21], int p1_score, int p2_score, int time, char *font_path) {
  resumeSection rs;
  Geometry g;

  char *p1_score_str = malloc(10*sizeof(char));
  char *time_str = malloc(20*sizeof(char));
  char *p2_score_str = malloc(10*sizeof(char));


  int min = (time / 1000) / 60;
  int sec = (time / 1000) - min*60;
  sprintf(time_str, "%dm : %ds", min, sec);
  sprintf(p1_score_str, "%d", p1_score);
  sprintf(p2_score_str, "%d", p2_score);

  
  rs.exist = true;
  
  g.width = container.width/5;
  g.height = container.height;
  g.posX = container.posX;
  g.posY = container.posY;

  rs.width = container.width;
  rs.height = container.height;
  rs.posX = container.posX;
  rs.posY = container.posY;


  rs.p1_name_lbl = get_new_label(g, p1_name, MLV_COLOR_RED, font_path);
  g.posX += g.width;
  rs.p1_score_lbl = get_new_label(g, p1_score_str, MLV_COLOR_RED, font_path);
  g.posX += g.width;
  rs.time_lbl = get_new_label(g, time_str, MLV_COLOR_RED, font_path);
  g.posX += g.width;
  rs.p2_score_lbl = get_new_label(g, p2_score_str, MLV_COLOR_RED, font_path);
  g.posX += g.width;
  rs.p2_name_lbl = get_new_label(g, p2_name, MLV_COLOR_RED, font_path);
  
  rs.is_hover = false;
  rs.is_select = false;
  
  return rs;
}


/* GLOBAL */
void set_hover_resume_section(resumeSection *this) {
  if (this == NULL || !this->exist || this->is_hover) {return;}
  this->is_hover = true;
}

/* GLOBAL */
void unset_hover_resume_section(resumeSection *this) {
  if (this == NULL || !this->exist || !this->is_hover) {return;}
  this->is_hover = false;
}

/* GLOBAL */
void set_select_resume_section(resumeSection *this) {
  if (this == NULL || !this->exist || this->is_select) {return;}
  this->is_select = true;
}

/* GLOBAL */
void unset_select_resume_section(resumeSection *this) {
  if (this == NULL || !this->exist || !this->is_select) {return;}
  this->is_select = false;
}
