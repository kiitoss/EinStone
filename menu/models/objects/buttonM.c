#include "../../menuHeader.h"
#include "../../makhead.h"

/* GLOBAL */
Button get_new_button(Geometry g, char *text, MLV_Color color, char *font_path, menu_choice value) {
  Button btn;
  btn.posX = g.posX;
  btn.posY = g.posY;
  btn.text = text;
  btn.color = color;
  btn.font_path = font_path;
  btn.is_hover = false;
  btn.is_select = false;
  btn.value = value;
  btn.is_hidden = false;
  btn.font_size = get_object_font_size(text, font_path, g.width, g.height);
  set_object_dimension(text, font_path, btn.font_size, &btn.width, &btn.height);
  return btn;
}
