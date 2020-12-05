#include "../gameHeader.h"
#include "../makhead.h"

int get_rectsize() {
  unsigned int win_width, win_height;
  int rectsize;
  MLV_get_desktop_size(&win_width, &win_height);
  rectsize = ((win_width / NB_COLUMNS) > (win_height / NB_ROWS)) ? win_height / NB_ROWS : win_width / NB_COLUMNS;
  return rectsize;
}

void launch_game(int rectsize) {
  Texture_Manager TM = init_TM();
  Game_Manager GM = init_GM(rectsize);
}

int main(int argc, char *argv[]) {
  int rectsize = get_rectsize();
  MLV_create_window("EinStone", "EinStone", rectsize*NB_COLUMNS, rectsize*NB_ROWS);
  MLV_enable_full_screen();
  launch_game(rectsize);
  MLV_wait_seconds(2);
  MLV_free_window();
  exit(0);
}
