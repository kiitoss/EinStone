#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
void draw_game(Game_Manager *GM, Texture_Manager *TM) {
  draw_window(GM, TM);
  MLV_update_window();
}
