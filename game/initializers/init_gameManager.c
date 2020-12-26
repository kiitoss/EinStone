#include "../../mainHeader.h"
#include "../makhead.h"

/* GLOBAL */
Game_Manager init_GM(Window *window, Texture_Manager *TM, menu_choice gamemode,menu_choice difficulty,char *p1_name,char *p2_name) {
  Game_Manager GM;
  int i;
  GM.id = 0;
  GM.in_game = true;
  GM.gamemode = gamemode;
  GM.difficulty = difficulty;
  GM.window = *window;
  for (i=0; i<NB_FRIENDS; i++) {
    GM.friend_spawners[i] = init_FS(i, TM, window);
  }
  for (i=0; i<NB_ENEMIES; i++) {
    GM.enemy_spawners[i] = init_ES(i, TM, window);
  }
  GM.p1 = init_p1(p1_name);
  GM.p2 = init_p2(p2_name);
  
  for (i=0; i<NB_ROWS; i++) {
    GM.rows[i] = init_row(window->rectsize);
  }
  
  GM.last_refresh = MLV_get_time();
  GM.duration = -MLV_get_time();
  return GM;
}
