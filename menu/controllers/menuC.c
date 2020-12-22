#include "../menuHeader.h"
#include "../makhead.h"

int launch_menu() {
  int width, height;
  width = 700;
  height = 700;
  MLV_create_window("TEST", "TEST", width, height);
  launch_main_page(width, height);
  MLV_free_window();
  exit(0);
}
