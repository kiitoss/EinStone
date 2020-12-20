#include "../../menuHeader.h"
#include "../../makhead.h"

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
  this->is_hidden = true;
}

/* GLOBAL */
void unset_hidden_lbl(Label *this) {
  this->is_hidden = false;
}

/* GLOBAL */
void set_label_geometry(Label *this, int posX) {
  if (this->is_hidden) {return;}
  this->posX = posX;
}
