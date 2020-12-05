#include "../gameHeader.h"
#include "../makhead.h"

int get_rectsize(unsigned int win_width, unsigned int win_height) {
  int rectsize;
  rectsize = ((win_width / NB_COLUMNS) > (win_height / NB_ROWS)) ? win_height / NB_ROWS : win_width / NB_COLUMNS;
  return rectsize;
}

/* GLOBAL */
Window init_window(unsigned int win_width, unsigned int win_height) {
  Window window;
  window.rectsize = get_rectsize(win_width, win_height);
  window.width = window.rectsize * NB_COLUMNS;
  window.height = window.rectsize * NB_ROWS;
  return window;
}
