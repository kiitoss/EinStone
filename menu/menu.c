#include "../headers/global_header.h"


int main(int argc, char *argv[]) {
  unsigned int win_width, win_height;
  int width, height;
  printf("%d, %s\n", argc, *argv);
  MLV_get_desktop_size(&win_width, &win_height);
  width = win_width / 2;
  height = win_height / 2;
  MLV_create_window("EinStone", "EinStone", width, height);
  
  MLV_enable_full_screen();
  
  launch_main_page(width, height);
  MLV_free_window();
  exit(0);
}
