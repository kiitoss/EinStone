#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
Gold get_new_gold(int centerX, int centerY, int rectsize) {
  Gold g;
  g.centerX = centerX;
  g.centerY = centerY;
  g.time_left = 10000;
  g.radius = 1;
  g.max_radius = rectsize/2;
  g.value = 10;
  return g;
}
