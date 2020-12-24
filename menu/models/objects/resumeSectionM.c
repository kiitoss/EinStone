#include "../../menuHeader.h"
#include "../../makhead.h"

/* GLOBAL */
bool is_resumeSection_hover(resumeSection *this, int posX, int posY) {
  if (this != NULL && this->exist && posX >= this->posX && posX <= this->posX + this->width && posY >= this->posY && posY <= this->posY + this->height) {
    return true;
  }
  return false;
}



/* GLOBAL */
resumeSection get_new_resumeSection(Geometry container, char *text, char *font_path) {
  resumeSection rs;
  Geometry g;
  
  rs.exist = true;
  
  g.width = container.width;
  g.height = container.height;
  g.posX = container.posX;
  g.posY = container.posY;

  rs.width = container.width;
  rs.height = container.height;
  rs.posX = container.posX;
  rs.posY = container.posY;

  rs.section_lbl = get_new_label(g, text, MLV_COLOR_RED, font_path);
  rs.is_hover = false;
  rs.is_select = false;
  
  return rs;
}


/* GLOBAL */
void set_hover_resume_section(resumeSection *this) {
  if (this == NULL || !this->exist) {return;}
  this->is_hover = true;
}

/* GLOBAL */
void unset_hover_resume_section(resumeSection *this) {
  if (this == NULL || !this->exist) {return;}
  this->is_hover = false;
}

/* GLOBAL */
void set_select_resume_section(resumeSection *this) {
  if (this == NULL || !this->exist) {return;}
  this->is_select = true;
}

/* GLOBAL */
void unset_select_resume_section(resumeSection *this) {
  if (this == NULL || !this->exist) {return;}
  this->is_select = false;
}
