#include "../../headers/global_header.h"



/* Retourne vrai si la section est survolée, faux sinon. */
bool is_resume_section_hover(Resume_Section *this, int posX, int posY) {
  if (this != NULL && this->exist && posX >= this->posX && posX <= this->posX + this->width && posY >= this->posY && posY <= this->posY + this->height) {
    return true;
  }
  return false;
}



/* Retourne une nouvelle section avec les données d'une ancienne partie. */
Resume_Section get_new_resume_section(Game_Manager *GM, Geometry container, char *font_path) {
  Resume_Section rs;
  Geometry g;
  char *p1_score_str, *time_str;
  int min, sec;

  /* Si l'ancienne partie n'existe pas, on créé un objet Resume_Section vide avec un attribut exist = false pour ne pas le dessiner plus tard. */
  if (GM == NULL) {
    rs.exist = false;
    return rs;
  }

  rs.exist = true;
  rs.GM = GM;

  /* Allocation de mémoire pour nos deux chaînes de caractères. */
  p1_score_str = malloc(21*sizeof(char));
  time_str = malloc(21*sizeof(char));

  min = (GM->duration / 1000) / 60;
  sec = (GM->duration / 1000) - min*60;

  sprintf(time_str, "%dm : %ds", min, sec);
  sprintf(p1_score_str, "%d", GM->p1.score);
  
  g.width = container.width/4;
  g.height = container.height;
  g.posX = container.posX;
  g.posY = container.posY;

  rs.width = container.width;
  rs.height = container.height;
  rs.posX = container.posX;
  rs.posY = container.posY;


  rs.p1_name_lbl = get_new_label(g, GM->p1.name, MLV_COLOR_RED, font_path);
  g.posX += g.width;
  rs.p1_score_lbl = get_new_label(g, p1_score_str, MLV_COLOR_RED, font_path);
  g.posX += g.width;
  rs.time_lbl = get_new_label(g, time_str, MLV_COLOR_RED, font_path);
  g.posX += g.width;
  rs.p2_name_lbl = get_new_label(g, GM->p2.name, MLV_COLOR_RED, font_path);
  rs.is_hover = false;
  rs.is_select = false;
  
  return rs;
}



/* Affecte la valeur vrai à la variable is_hover de la section. */
void set_hover_resume_section(Resume_Section *this) {
  if (this == NULL || !this->exist || this->is_hover) {return;}
  this->is_hover = true;
}



/* Affecte la valeur faux à la variable is_hover de la section. */
void unset_hover_resume_section(Resume_Section *this) {
  if (this == NULL || !this->exist || !this->is_hover) {return;}
  this->is_hover = false;
}



/* Affecte la valeur vrai à la variable is_select de la section. */
void set_select_resume_section(Resume_Section *this) {
  if (this == NULL || !this->exist || this->is_select) {return;}
  this->is_select = true;
}



/* Affecte la valeur faux à la variable is_select de la section. */
void unset_select_resume_section(Resume_Section *this) {
  if (this == NULL || !this->exist || !this->is_select) {return;}
  this->is_select = false;
}



/* Retourne un objet Resume_Page initialisé. */
Resume_Page init_resume_page(int width, int height, GM_list_games GMG) {
  Resume_Page rp;
  Geometry g;
  int i;
  int margin_title = height/3 * 0.2;
  int title_height = height/3 * 0.8;
  
  int margin_row = 2*height/3 * 0.3/(SAVED_GAMES+1);
  int row_height = 2*height/3 * 0.7/(SAVED_GAMES+1);
  char *font_path = "./resources/font/Amatic-Bold.ttf";

  /* Initialisation des pointeurs permettant de savoir à tout moment le bouton survolé, la section survolée et la section selectionnée. */
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

  /* Création des sections comprenant les informations des anciennes parties. */
  for (i=0; i<SAVED_GAMES; i++) {
    if (GMG[i].id == 0) {
      rp.sections[i] = get_new_resume_section(NULL, g, font_path);
      rp.sections[i].exist = false;
    }
    else {
      rp.sections[i] = get_new_resume_section(&GMG[i], g, font_path);
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



/* Retourne un pointeur correspondant au bouton survolé de la page continuer. */
Button *get_resume_page_hover_btn(Resume_Page *this, int posX, int posY) {
  Button *hover_btn = NULL;
  if (is_btn_hover(&this->back_btn, posX, posY)) {
    hover_btn = &this->back_btn;
  }
  else if (is_btn_hover(&this->launch_btn, posX, posY)) {
    hover_btn = &this->launch_btn;
  }
  return hover_btn;
}



/* Retourne un pointeur correspondant à la section survolée de la page continuer. */
Resume_Section *get_resume_page_hover_section(Resume_Page *this, int posX, int posY) {
  Resume_Section *hover_section = NULL;
  int i;
  for (i=0; i<SAVED_GAMES; i++) {
    if (is_resume_section_hover(&this->sections[i], posX, posY)) {
      hover_section = &this->sections[i];
    }
  }
  return hover_section;
}
