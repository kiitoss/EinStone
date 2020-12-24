#include "../gameHeader.h"
#include "../makhead.h"

void get_weak_row(Game_Manager *GM){
  int i;
  GM->p2.chosen_row = 0;
  for(i=1;i<NB_ROWS;i++){
    if(GM->rows[i].nb_enemies < GM->rows[GM->p2.chosen_row].nb_enemies){
      GM->p2.chosen_row = i;
    }
  }
}
void get_enemy(Game_Manager *GM){
   if(GM->p2.money <= GM->enemy_spawners[GM->p2.chosen_enemy].price){    
     GM->p2.chosen_enemy = rand() % NB_ENEMIES;
   }
  
  
}
/* GLOBAL */
void update_ia(Game_Manager *GM){
  get_weak_row(GM);
  get_enemy(GM);
  p2_buy_enemy(&GM->p2, &GM->rows[GM->p2.chosen_row] ,&GM->enemy_spawners[GM->p2.chosen_enemy], GM->window.field.width, GM->p2.chosen_row * GM->window.rectsize);
}
