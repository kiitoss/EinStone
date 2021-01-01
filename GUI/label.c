#include "../headers/global_header.h"



/* Dessine un label. */
void draw_label(Label *this) {
  MLV_Font* font;

  if (this->is_hidden) {return;}

  font = MLV_load_font(this->font_path , this->font_size);
  MLV_draw_adapted_text_box_with_font(this->posX, this->posY, this->text, font, 0, MLV_rgba(0,0,0,0), this->color, MLV_rgba(0,0,0,0), MLV_TEXT_CENTER);
  MLV_free_font(font);
}



/* Retourne un nouveau label. */
Label get_new_label(Geometry g, char *text, MLV_Color color, char *font_path) {
  Label lbl;
  lbl.text = text;
  lbl.color = color;
  lbl.font_path = font_path;

  /* On cherche à faire un label aussi grand que possible, centré, selon la géométrie g. */
  /* Affectation d'une taille de police optimale (la plus grande possible). */
  lbl.font_size = get_object_font_size(text, font_path, g.width, g.height);

  /* Affectation des posX et posY du label selon la taille trouvée précédemment. */
  set_object_dimension(text, font_path, lbl.font_size, &lbl.width, &lbl.height);

  /* Affectation des posX et posY du label selon la taille trouvée précédemment. */
  lbl.posX = g.posX + (g.width - lbl.width)/2;
  lbl.posY = g.posY + (g.height - lbl.height)/2;

  lbl.is_hidden = false;
  return lbl;
}



/* Affecte la valeur vrai à la variable is_hidden du label. */
void set_hidden_lbl(Label *this) {
  if (this->is_hidden) {return;}
  this->is_hidden = true;
}



/* Affecte la valeur faux à la variable is_hidden du label. */
void unset_hidden_lbl(Label *this) {
  if (!this->is_hidden) {return;}
  this->is_hidden = false;
}



/* Modifie la geometrie du label. */
void set_label_geometry(Label *this, int posX) {
  if (this->is_hidden) {return;}
  this->posX = posX;
}
