#include "../menuHeader.h"
#include "../makhead.h"

int main(int argc, char *argv[]) {
  int width, height;
  width = 700;
  height = 700;
  MLV_create_window("TEST", "TEST", width, height);
  launch_main_page(width, height);
  MLV_free_window();
  exit(0);
}
