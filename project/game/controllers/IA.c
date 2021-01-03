#include "../../headers/global_header.h"



/*
  Cherche la ligne la plus fragile,
  calcule la somme de la vie des alliés par ligne
  et retourne le nombre d'alliés minimum de la ligne la plus faible.
*/
int get_weak_row(Game_Manager *GM){
  int i, j, k;
  int nb_friends, min_friends, min_enemies, max_life;
  int weak_row[NB_ROWS], sum_life_friend[NB_ROWS];
  
  min_friends = NB_COLUMNS;
  GM->p2.chosen_row = 0;
  k = 0;

  /*
    Affecte les lignes avec le plus faible nombre d'ennemies dans week_row.
    Calcule la somme de la vie des alliés dans chaque lignes.
  */
  for(i=0; i<NB_ROWS; i++){
    nb_friends = 0;
    sum_life_friend[i] = 0;
    for (j=0; j<NB_COLUMNS; j++) {
      if (is_friend(&GM->rows[i].friends[j])) {
	nb_friends++;
	sum_life_friend[i] += GM->rows[i].friends[j].life;
      }
    }
    
    if (nb_friends < min_friends) {
      min_friends = nb_friends;
      k = 0;
      weak_row[k++] = i;
    }
    else if (nb_friends == min_friends) {
      weak_row[k++] = i;
    }
  }

  
  min_enemies = MAX_ENEMIES;
  max_life = sum_life_friend[weak_row[0]];

  /* Choisis ensuite la ligne la plus faible. */
  for(i=0; i<k; i++){
    if (GM->rows[weak_row[i]].nb_enemies  < min_enemies || sum_life_friend[weak_row[i]] < max_life){
      min_enemies = GM->rows[weak_row[i]].nb_enemies;
      max_life = sum_life_friend[weak_row[i]];

      GM->p2.chosen_row = weak_row[i];
    }
  }
  
  return min_friends;
}



/* Envoie le bon ennemie sur la ligne la plus faible. */
void get_enemy(Game_Manager *GM,int min_friend){
  int i;
  if(min_friend == 0){
    for(i=0;i<GM->rows[GM->p2.chosen_row].nb_enemies;i++){
      if (GM->p2.money >= GM->enemy_spawners[0].price && GM->rows[GM->p2.chosen_row].enemies[i].posX > GM->window.field.posX){
	GM->p2.chosen_enemy = 0;
      }
      else {return;}
    }
  }
  
  if (min_friend > 0 && min_friend <= 2){
    if (GM->p2.money >= GM->enemy_spawners[NB_ENEMIES/2].price){
      GM->p2.chosen_enemy = rand() % (NB_ENEMIES/2 - 0 + 1) + 0;
    }
    else {return;}
  }
  
  else if (min_friend>2){
    if (GM->p2.money >= GM->enemy_spawners[NB_ENEMIES-1].price){
      GM->p2.chosen_enemy = rand() % NB_ENEMIES;
    }
    else {return;}
  }
  p2_buy_enemy(&GM->p2, &GM->rows[GM->p2.chosen_row] ,&GM->enemy_spawners[GM->p2.chosen_enemy], GM->window.field.width, GM->p2.chosen_row * GM->window.rectsize);

}



/* Met à jour l'IA. */
void update_IA(Game_Manager *GM){
  int min_friend = get_weak_row(GM);
  get_enemy(GM, min_friend);
}
