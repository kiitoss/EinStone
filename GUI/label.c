#include "GUI_header.h"

/* GLOBAL */
void draw_label(Label *this) {
  MLV_Font* font;

  if (this->is_hidden) {return;}

  font = MLV_load_font(this->font_path , this->font_size);
  MLV_draw_adapted_text_box_with_font(this->posX, this->posY, this->text, font, 0, MLV_rgba(0,0,0,0), this->color, MLV_rgba(0,0,0,0), MLV_TEXT_CENTER);
  MLV_free_font(font);
}

/* GLOBAL */
Label get_new_label(Geometry g, char *text, MLV_Color color, char *font_path) {
  Label lbl;
  lbl.text = text;
  lbl.color = color;
  lbl.font_path = font_path;
  lbl.font_size = get_object_font_size(text, font_path, g.width, g.height);
  set_object_dimension(text, font_path, lbl.font_size, &lbl.width, &lbl.height);


  lbl.posX = g.posX + (g.width - lbl.width)/2;
  lbl.posY = g.posY + (g.height - lbl.height)/2;

  lbl.is_hidden = false;
  return lbl;
}


/* GLOBAL */
void set_hidden_lbl(Label *this) {
  if (this->is_hidden) {return;}
  this->is_hidden = true;
}

/* GLOBAL */
void unset_hidden_lbl(Label *this) {
  if (!this->is_hidden) {return;}
  this->is_hidden = false;
}

/* GLOBAL */
void set_label_geometry(Label *this, int posX) {
  if (this->is_hidden) {return;}
  this->posX = posX;
}
