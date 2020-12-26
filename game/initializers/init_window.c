#include "../../mainHeader.h"
#include "../makhead.h"

int get_rectsize(unsigned int win_width, unsigned int win_height, menu_choice gamemode) {
  int rectsize;
  int nb_rows = (gamemode == SOLO) ? NB_ROWS + 1 : NB_ROWS + 2;
  rectsize = ((win_width / NB_COLUMNS) > (win_height / nb_rows)) ? win_height / nb_rows : win_width / NB_COLUMNS;
  return rectsize;
}

/* GLOBAL */
Window init_window(unsigned int win_width, unsigned int win_height, menu_choice gamemode) {
  Window window;

  window.rectsize = get_rectsize(win_width, win_height, gamemode);
  window.width = win_width;
  window.height = win_height;

  window.friend_home.posX = 0;
  window.friend_home.posY = 0;
  window.friend_home.width = (win_width - NB_COLUMNS * window.rectsize) / 2;
  window.friend_home.height = win_height;


  window.friend_spawner.posX = window.friend_home.posX + window.friend_home.width;
  window.friend_spawner.posY = 0;
  window.friend_spawner.width = NB_COLUMNS * window.rectsize;
  window.friend_spawner.height = window.rectsize;

  window.field.posX = window.friend_spawner.posX;
  window.field.posY = window.friend_spawner.height;
  window.field.width = NB_COLUMNS * window.rectsize;
  window.field.height = NB_ROWS * window.rectsize;

  window.enemy_home.posX = window.field.posX + window.field.width;
  window.enemy_home.posY = 0;
  window.enemy_home.width = (win_width - NB_COLUMNS * window.rectsize) / 2;
  window.enemy_home.height = win_height;
  
  if (gamemode == MULTI) {
    window.enemy_spawner.posX = window.friend_spawner.posX;
    window.enemy_spawner.posY = window.field.posY + window.field.height;
    window.enemy_spawner.width = NB_COLUMNS * window.rectsize;
    window.enemy_spawner.height = window.rectsize;
  }
  return window;
}
