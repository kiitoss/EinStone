#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
Gold get_new_gold(int gridX, int gridY, Window *window, MLV_Image *img) {
  Gold g;
  g.centerX = (rand() % window->rectsize) + gridX*window->rectsize + window->field.posX;
  g.centerY = (rand() % window->rectsize) + gridY*window->rectsize + window->field.posY;
  g.time_left = 10000;
  g.radius = 1;
  g.max_radius = window->rectsize/4;
  g.original_img = img;
  g.value = 10;
  return g;
}
