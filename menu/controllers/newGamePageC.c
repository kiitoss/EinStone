#include "../menuHeader.h"
#include "../makhead.h"

void update_newgame_page(newgamePage *ngp) {
  while (true) {
  }
}

/* GLOBAL */
void launch_newgame_page(int width, int height) {
  newgamePage ngp = init_newgame_page(width, height);
  draw_newgame_page(&ngp);
  update_newgame_page(&ngp);
}
