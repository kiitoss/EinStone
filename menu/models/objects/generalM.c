#include "../../menuHeader.h"
#include "../../makhead.h"

/* GLOBAL */
void set_object_dimension(char *text, char *font_path, int font_size, int *object_width, int *object_height) {
  MLV_Font *font = MLV_load_font(font_path, font_size);
  MLV_get_size_of_adapted_text_box_with_font(text, font, 0, object_width, object_height);
  MLV_free_font(font);
}

/* GLOBAL */
int get_object_font_size(char *text, char *font_path, int max_width, int max_height) {
  MLV_Font *font;
  int font_size = 1;
  int width = 0;
  int height = 0;
  while (width <= max_width && height <= max_height) {
    font = MLV_load_font(font_path, font_size);
    MLV_get_size_of_adapted_text_box_with_font(text, font, 0, &width, &height);
    MLV_free_font(font);
    font_size++;
  }
  return font_size;
}
