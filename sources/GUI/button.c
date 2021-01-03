#include "../headers/global_header.h"



/* Dessine un bouton. */
void draw_button(Button *this) {
  MLV_Font* font;
  MLV_Color background_color;
  int border_size = 5;
  
  if (this->is_hidden) {return;}
  
  font = MLV_load_font(this->font_path , this->font_size);

  /* Affectation d'une couleur différente si le bouton est survolé ou selectionné. */
  if (this->is_select || this->is_hover) {
    if (this->is_select) {
      background_color = MLV_COLOR_GREEN;
    }
    else {
      background_color = MLV_COLOR_ORANGE;
    }
  }
  else {
    background_color = this->background_color;
  }

  MLV_draw_rectangle(this->container.posX, this->container.posY - border_size, this->container.width, this->container.height + 2*border_size, background_color);
  MLV_draw_filled_rectangle(this->container.posX, this->container.posY, this->container.width, this->container.height, background_color);

  MLV_draw_adapted_text_box_with_font(this->posX, this->posY, this->text, font, 0, MLV_rgba(0,0,0,0), this->color, MLV_rgba(0,0,0,0), MLV_TEXT_CENTER);
  MLV_free_font(font);
}



/* Retourne vrai si le bouton est survolé, faux sinon. */
bool is_btn_hover(Button *this, int posX, int posY) {
  if (this != NULL && posX >= this->container.posX && posX <= this->container.posX + this->container.width && posY >= this->container.posY && posY <= this->container.posY + this->container.height) {
    return true;
  }
  return false;
}



/* Retourne vrai si le bouton est selectionné, faux sinon. */
bool is_btn_select(Button *this) {
  return (this != NULL && this->is_select) ? true : false;
}



/* Retourne un nouveau bouton. */
Button get_new_button(Geometry g, char *text, MLV_Color color, MLV_Color background_color, char *font_path, btn_value value) {
  Button btn;
  btn.container = g;
  btn.text = text;
  btn.color = color;
  btn.background_color = background_color;
  btn.font_path = font_path;
  btn.is_hover = false;
  btn.is_select = false;
  btn.value = value;
  btn.is_hidden = false;

  /* On cherche à faire un bouton aussi grand que possible, centré, selon la géométrie g. */
  /* Affectation d'une taille de police optimale (la plus grande possible). */
  btn.font_size = get_object_font_size(text, font_path, g.width, g.height);

  /* Affectation de la taille du bouton, selon la taille de la police trouvée précédemment. */
  set_object_dimension(text, font_path, btn.font_size, &btn.width, &btn.height);

  /* Affectation des posX et posY du bouton selon la taille trouvée précédemment. */
  btn.posX = g.posX + (g.width - btn.width)/2;
  btn.posY = g.posY + (g.height - btn.height)/2;

  /* Réaffectation de la taille du bouton pour qu'il soit finalement de la taille originelle. */
  btn.width = g.width;
  btn.height = g.height;
  
  return btn;
}



/* Affecte la valeur vrai à la variable is_hover du bouton. */
void set_hover_btn(Button *this) {
  if (this == NULL || this->is_hover) {return;}
  this->is_hover = true;
}



/* Affecte la valeur faux à la variable is_hover du bouton. */
void unset_hover_btn(Button *this) {
  if (this == NULL || !this->is_hover) {return;}
  this->is_hover = false;
}



/* Affecte la valeur vrai à la variable is_select du bouton. */
void set_select_btn(Button *this) {
  if (this == NULL || this->is_select) {return;}
  this->is_select = true;
}



/* Affecte la valeur faux à la variable is_select du bouton. */
void unset_select_btn(Button *this) {
  if (this == NULL || !this->is_select) {return;}
  this->is_select = false;
}



/* Affecte la valeur vrai à la variable is_hidden du bouton. */
void set_hidden_btn(Button *this) {
  if (this == NULL || this->is_hidden) {return;}
  this->is_hidden = true;
}



/* Affecte la valeur faux à la variable is_hidden du bouton. */
void unset_hidden_btn(Button *this) {
  if (this == NULL || !this->is_hidden) {return;}
  this->is_hidden = false;
}
