#include "../gameHeader.h"
#include "../makhead.h"

int get_rectsize(unsigned int win_width, unsigned int win_height, menu_choice gamemode) {
  int rectsize;
  int nb_rows = (gamemode == SOLO) ? NB_ROWS + 1 : NB_ROWS + 2;
  int nb_columns = NB_COLUMNS + 4;
  rectsize = ((win_width / nb_columns) > (win_height / nb_rows)) ? win_height / nb_rows : win_width / nb_columns;
  return rectsize;
}

/* GLOBAL */
Window init_window(unsigned int win_width, unsigned int win_height, menu_choice gamemode) {
  Window window;
  window.rectsize = get_rectsize(win_width, win_height, gamemode);
  window.width = window.rectsize * (NB_COLUMNS + 4);
  window.height = (gamemode == SOLO) ? window.rectsize * (NB_ROWS + 1) : window.rectsize * (NB_ROWS + 2);
  window.friend_spawner.posX = 2*window.rectsize;
  window.friend_spawner.posY = 0;
  window.friend_spawner.width = NB_COLUMNS * window.rectsize;
  window.friend_spawner.height = window.rectsize;

  window.field.posX = 2*window.rectsize;
  window.field.posY = window.friend_spawner.height;
  window.field.width = NB_COLUMNS * window.rectsize;
  window.field.height= NB_ROWS * window.rectsize;
  
  if (gamemode == MULTI) {
    window.enemy_spawner.posX = 2*window.rectsize;
    window.enemy_spawner.posY = window.field.posY + window.field.height;
    window.enemy_spawner.width = NB_COLUMNS * window.rectsize;
    window.enemy_spawner.height = window.rectsize;
  }
  return window;
}
