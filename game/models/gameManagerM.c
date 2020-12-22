#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
Game_Manager init_GM(Window *window, Texture_Manager *TM) {
  Game_Manager GM;
  int i;
  GM.window = *window;
  for (i=0; i<NB_FRIENDS; i++) {
    GM.friend_spawners[i] = init_FS(i, TM, window);
  }
  for (i=0; i<NB_ENEMIES; i++) {
    GM.enemy_spawners[i] = init_ES(i, TM, window);
  }
  GM.p1 = init_p1();
  GM.p2 = init_p2();
  
  for (i=0; i<NB_ROWS; i++) {
    GM.rows[i] = init_row();
  }
  
  GM.last_refresh = MLV_get_time();
  return GM;
}
