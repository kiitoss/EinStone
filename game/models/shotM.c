#include "../../mainHeader.h"
#include "../makhead.h"

/* GLOBAL */
Shot get_new_shot(int posX, int posY, int rectsize, int attack) {
  Shot s;
  s.posX = posX;
  s.posY = posY;
  s.attack = attack;
  s.speed = (rectsize/20 == 0) ? 1 : rectsize/30;
  return s;
}
