#include "../../menuHeader.h"
#include "../../makhead.h"

void set_input_object(Input *this) {
  MLV_Font *font = MLV_load_font(this->font_path, this->font_size);

  this->object = MLV_create_input_box_with_font(this->posX, this->posY, this->width, this->height, MLV_rgba(0,0,0,0), this->color, MLV_COLOR_BLACK, this->placeholder, font);
  this->font = font;
}

/* GLOBAL */
Input get_new_input(Geometry g, char *placeholder, MLV_Color color, char *font_path) {
  Input input;
  char *input_text = "Joueur X: XXXXXXXXXXXX";
  input.placeholder = placeholder;
  input.color = color;

  input.font_path = font_path;

  input.font_size = get_object_font_size(input_text, font_path, g.width, g.height);
  set_object_dimension(input_text, font_path, input.font_size, &input.width, &input.height);
  
  input.posX = g.posX + (g.width - input.width)/2;
  input.posY = g.posY;
  input.width = g.width;
  input.height = g.height;

  input.is_hidden = false;
  
  set_input_object(&input);
  return input;
}

/* GLOBAL */
void free_input(Input *this) {
  if (this->object == NULL) {return;}

  MLV_free_input_box(this->object);
  MLV_free_font(this->font);
  this->object = NULL;
}

/* GLOBAL */
void set_hidden_input(Input *this) {
  if (this->object == NULL) {return;}
  this->is_hidden = true;
  MLV_change_input_box_geometry(this->object, 0, 0, 0, 0);
}

/* GLOBAL */
void unset_hidden_input(Input *this) {
  if (this->object == NULL) {return;}
  this->is_hidden = false;
  MLV_change_input_box_geometry(this->object, this->posX, this->posY, this->width, this->height);
}

/* GLOBAL */
void set_input_geometry(Input *this, int posX, int width) {
  if (this->object == NULL || this->is_hidden) {return;}
  this->posX = posX;
  this->width = width;
  MLV_change_input_box_geometry(this->object, this->posX, this->posY, this->width, this->height);
}

/* GLOBAL */
bool exist_input(Input *this) {
  return this->object != NULL;
}
