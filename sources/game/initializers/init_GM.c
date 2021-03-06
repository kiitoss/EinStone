#include "../../headers/global_header.h"



/* Retourne le joueur 1 initialisé. */
Player_1 init_p1(char *p1_name) {
  Player_1 p1;
  p1.chosen_friend = -1;
  p1.money = INIT_GOLD_P1;
  p1.last_free_gold = MLV_get_time();
  p1.score = 0;
  set_player_money_str(p1.money, p1.money_str);
  p1.life = LIFE_P1;
  p1.is_deleting = false;
  strncpy(p1.name, p1_name, 19);
  p1.name[20] = '\0';
  return p1;
}



/* Retourne le joueur 2 initialisé. */
Player_2 init_p2(char *p2_name) {
  Player_2 p2;
  p2.chosen_row = 0;
  p2.chosen_enemy = 0;
  p2.money = INIT_GOLD_P2;
  p2.last_free_gold = MLV_get_time();
  strncpy(p2.name, p2_name, 19);
  p2.name[20] = '\0';
  set_player_money_str(p2.money, p2.money_str);
  return p2;
}



/* Retourne une ligne initialisée. */
Row init_row(int rectsize) {
  Row r;
  int i;
  for (i=0; i<NB_COLUMNS; i++) {
    r.friends[i].id_friend = -1;
  }
  r.nb_enemies = 0;
  r.nb_shots = 0;
  r.nb_golds = 0;
  r.rectsize = rectsize;
  return r;
}



/* Retourne un objet Game_Manager initialisé. */
Game_Manager init_GM(Window *window, Texture_Manager *TM, btn_value gamemode,btn_value difficulty,char *p1_name,char *p2_name) {
  Game_Manager GM;
  int i;

  /* On initialise l'id à 0 pour une nouvelle partie, un id définitif sera affecté quand l'utilisateur quittera la partie. */
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

  /* La durée de la partie est initialisé à -time(), une fois la fin de la partie, il suffira de faire duration += time() pour avoir le temps final. */
  GM.duration = -MLV_get_time();
  
  GM.last_state_mouse = MLV_RELEASED;
  GM.last_state_key = MLV_RELEASED;
  return GM;
}
