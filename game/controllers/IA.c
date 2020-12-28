#include "../game_header.h"


int get_weak_row(Game_Manager *GM){
  int k,i, j;
  int nb_friends, max_friends;
  int nb_friends_min,max_enemies,max_life;
  int weak_row[NB_ROWS+1],sum_life_friend[NB_ROWS+1];
  
  max_friends = NB_COLUMNS;
  max_life = 10000000;
  GM->p2.chosen_row = 0;
  k = 0;
  
  for(i=0;i<NB_ROWS;i++){
    nb_friends = 0;
    sum_life_friend[i] = 0;
    for (j=0; j<NB_COLUMNS; j++) {
      if (is_friend(&GM->rows[i].friends[j])) {
	nb_friends++;
	sum_life_friend[i] += GM->rows[i].friends[j].life;
      }
    }
    if (nb_friends < max_friends) {
      max_friends = nb_friends;
    }
  }
  nb_friends_min = max_friends;
  
  for(i=0;i<NB_ROWS;i++){
    nb_friends = 0;
    for (j=0; j<NB_COLUMNS; j++) {
      if (is_friend(&GM->rows[i].friends[j])) {
	nb_friends++;
      }
    }
    if (nb_friends_min == nb_friends) {
      weak_row[k++] = i;
    } 
  }
  
  max_enemies = MAX_ENEMIES;

  for(i=0;i<k;i++){
    if (GM->rows[weak_row[i]].nb_enemies  < max_enemies ||  sum_life_friend[weak_row[i]] < max_life){
      max_enemies = GM->rows[weak_row[i]].nb_enemies;
      max_life = sum_life_friend[weak_row[i]];

      GM->p2.chosen_row = weak_row[i];
    }
    
  }
  
  return max_friends;
}

void get_enemy(Game_Manager *GM,int max_friend){
  int i;
  if(max_friend == 0){
    for(i=0;i<GM->rows[GM->p2.chosen_row].nb_enemies;i++){
      if (GM->p2.money >= GM->enemy_spawners[0].price && GM->rows[GM->p2.chosen_row].enemies[i].posX > GM->window.field.posX){
	GM->p2.chosen_enemy = 0;
      }
      else {return;}
    }
  }
  if (max_friend >0 && max_friend <= 2){
    if (GM->p2.money >= GM->enemy_spawners[1].price){
      GM->p2.chosen_enemy = rand() % (1 - 0 + 1) + 0;
    }
    else {return;}
  }
  
  else if (max_friend >2){
    if (GM->p2.money >= GM->enemy_spawners[NB_ENEMIES-1].price){
      GM->p2.chosen_enemy = rand() % NB_ENEMIES;
    }
    else {return;}
  }
  p2_buy_enemy(&GM->p2, &GM->rows[GM->p2.chosen_row] ,&GM->enemy_spawners[GM->p2.chosen_enemy], GM->window.field.width, GM->p2.chosen_row * GM->window.rectsize);

}

/* GLOBAL */
void update_IA(Game_Manager *GM){
  int max_friend;
  
  if(GM->gamemode == MULTI){return;}

  max_friend = get_weak_row(GM);
  get_enemy(GM,max_friend);
}
