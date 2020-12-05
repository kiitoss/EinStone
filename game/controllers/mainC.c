#include "../gameHeader.h"
#include "../makhead.h"

int main(int argc, char *argv[]) {
  unsigned int win_width, win_height;
  Texture_Manager TM;
  Game_Manager GM;
  Window window;
  MLV_get_desktop_size(&win_width, &win_height);
  
  window = init_window(win_width, win_height);

  MLV_create_window("EinStone", "EinStone", window.width, window.height);

  TM = init_TM();
  GM = init_GM(&window);
    
  MLV_enable_full_screen();
  MLV_wait_seconds(2);
  MLV_free_window();
  exit(0);
}
