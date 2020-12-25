#include "../../mainHeader.h"
#include "../makhead.h"

void get_weak_row(Game_Manager *GM){
  int i, j, nb_friends, max_friends;
  max_friends = NB_COLUMNS;
  GM->p2.chosen_row = 0;
  
  for(i=0;i<NB_ROWS;i++){
    nb_friends = 0;
    for (j=0; j<NB_COLUMNS; j++) {
      if (is_friend(&GM->rows[i].friends[j])) {
	nb_friends++;
      }
    }
    if (nb_friends < max_friends) {
      GM->p2.chosen_row = i;
      max_friends = nb_friends;
    }
  }
}

void get_enemy(Game_Manager *GM){
   if(GM->p2.money <= GM->enemy_spawners[GM->p2.chosen_enemy].price){    
     GM->p2.chosen_enemy = rand() % NB_ENEMIES;
   }
}
/* GLOBAL */
void update_IA(Game_Manager *GM){
  if (GM->gamemode == MULTI) {return;}
  get_weak_row(GM);
  get_enemy(GM);
  p2_buy_enemy(&GM->p2, &GM->rows[GM->p2.chosen_row] ,&GM->enemy_spawners[GM->p2.chosen_enemy], GM->window.field.width, GM->p2.chosen_row * GM->window.rectsize);
}
