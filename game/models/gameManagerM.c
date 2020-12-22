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
    /* GM.enemy_spawners[i] = init_ES(i, TM, window); */
  }
  printf("OK\n");
  return GM;
}
