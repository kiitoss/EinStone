#include "../gameHeader.h"
#include "../makhead.h"

void update_window(Game_Manager *GM, Texture_Manager *TM) {
  draw_game(GM, TM);
  /*
    update_window(GM, TM); */
}

int main(int argc, char *argv[]) {
  unsigned int win_width, win_height;
  Texture_Manager TM;
  Game_Manager GM;
  Window window;
  menu_choice gamemode = MULTI;
  
  MLV_get_desktop_size(&win_width, &win_height);
  
  window = init_window(win_width, win_height, gamemode);

  MLV_create_window("EinStone", "EinStone", window.width, window.height);

  TM = init_TM(window);
  GM = init_GM(&window, &TM);

  MLV_enable_full_screen();

  
  update_window(&GM, &TM);
   
  MLV_wait_seconds(2);
  MLV_free_window();
  exit(0);
}
