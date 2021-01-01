#include "../../headers/global_header.h"



/* Retourne un pointeur correspondant au bouton survolé de la page des scores. */
Button *get_score_page_hover_btn(Score_Page *this, int posX, int posY) {
  Button *hover_btn = NULL;
  if (is_btn_hover(&this->back_btn, posX, posY)) {
    hover_btn = &this->back_btn;
  }
  return hover_btn;
}



/* Retourne une nouvelle section avec les données d'une ancienne partie terminée. */
Score_Section get_new_score_section(Game_Manager *GM, Geometry container, char *font_path) {
  Score_Section ss;
  Geometry g;
  char *p1_score_str, *time_str;
  int min, sec;

  /* Si l'ancienne partie n'existe pas, on créé un objet Score_Section vide avec un attribut exist = false pour ne pas le dessiner plus tard. */
  if (GM == NULL) {
    ss.exist = false;
    return ss;
  }

  ss.exist = true;

  /* Allocation de mémoire pour nos deux chaînes de caractères. */
  p1_score_str = malloc(21*sizeof(char));
  time_str = malloc(21*sizeof(char));


  min = (GM->duration / 1000) / 60;
  sec = (GM->duration / 1000) - min*60;

  sprintf(time_str, "%dm : %ds", min, sec);
  sprintf(p1_score_str, "%d", GM->p1.score);
  
  
  g.width = container.width/3;
  g.height = container.height;
  g.posX = container.posX;
  g.posY = container.posY;

  ss.width = container.width;
  ss.height = container.height;
  ss.posX = container.posX;
  ss.posY = container.posY;


  ss.p1_name_lbl = get_new_label(g, GM->p1.name, MLV_COLOR_RED, font_path);
  g.posX += g.width;
  ss.p1_score_lbl = get_new_label(g, p1_score_str, MLV_COLOR_RED, font_path);
  g.posX += g.width;
  ss.time_lbl = get_new_label(g, time_str, MLV_COLOR_RED, font_path);
  
  return ss;
}



/* Retourne un objet Score_Page initialisé. */
Score_Page init_score_page(int width, int height, GM_list_scores GMS) {
  Score_Page sp;
  Geometry g;
  int i;
  int margin_title = height/3 * 0.2;
  int title_height = height/3 * 0.8;
  
  int margin_row = 2*height/3 * 0.3/(SAVED_SCORES+1);
  int row_height = 2*height/3 * 0.7/(SAVED_SCORES+1);
  char *font_path = "./resources/font/Amatic-Bold.ttf";

  /* Initialisation du pointeur permettant de savoir à tout moment le bouton survolé. */
  sp.hover_btn = NULL;
  
  g.width = width/2;
  g.height = title_height;
  g.posX = width/4;
  g.posY = 0;

  sp.width = width;
  sp.height = height;
  
  sp.title_lbl = get_new_label(g, "Ein Stone", MLV_COLOR_RED, font_path);

  g.height = row_height;
  g.posY += title_height + margin_title;

  /* Création des sections comprenant les scores des anciennes parties. */
  for (i=0; i<SAVED_SCORES; i++) {
    if (GMS[i].id == 0) {
      sp.sections[i] = get_new_score_section(NULL, g, font_path);
      sp.sections[i].exist = false;
    }
    else {
      sp.sections[i] = get_new_score_section(&GMS[i], g, font_path);
    }
    g.posY += row_height + margin_row;
  }

  g.width = width/4;
  g.posX = 0;
  sp.back_btn = get_new_button(g, "Back", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, BACK);

  return sp;
}
