#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
Game_Manager init_GM(Window *window) {
  Game_Manager GM;
  GM.window = *window;
  return GM;
}
