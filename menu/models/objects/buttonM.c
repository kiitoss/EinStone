#include "../../menuHeader.h"
#include "../../makhead.h"

/* GLOBAL */
bool is_btn_hover(Button *this, int posX, int posY) {
  if (posX >= this->container.posX && posX <= this->container.posX + this->container.width && posY >= this->container.posY && posY <= this->container.posY + this->container.height) {
    return true;
  }
  return false;
}

/* GLOBAL */
Button get_new_button(Geometry g, char *text, MLV_Color color, char *font_path, menu_choice value) {
  Button btn;
  btn.container = g;
  btn.text = text;
  btn.color = color;
  btn.font_path = font_path;
  btn.is_hover = false;
  btn.is_select = false;
  btn.value = value;
  btn.is_hidden = false;
  btn.font_size = get_object_font_size(text, font_path, g.width, g.height);
  set_object_dimension(text, font_path, btn.font_size, &btn.width, &btn.height);


  btn.posX = g.posX + (g.width - btn.width)/2;
  printf("%d, %d, %d\n", g.width, btn.width, btn.posX);
  btn.posY = g.posY + (g.height - btn.height)/2;
  btn.width = g.width;
  btn.height = g.height;
  return btn;
}

/* GLOBAL */
void set_hover_btn(Button *this) {
  this->is_hover = true;
}

/* GLOBAL */
void unset_hover_btn(Button *this) {
  this->is_hover = false;
}
