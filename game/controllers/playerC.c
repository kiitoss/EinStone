#include "../../mainHeader.h"
#include "../makhead.h"





/* Convertit le montant de l'or (int) en string. */
/* GLOBAL */
void set_player_money_str(int money, char money_str[10]) {
  sprintf(money_str, "%d", money);
}





/* Convertit la vie (int) en string. */
/* GLOBAL */
void set_player_life_str(int life, char life_str[10]) {
  sprintf(life_str, "%d", life);
}





/* Ajoute un montant au total d'or du joueur 1. */
/* GLOBAL */
void p1_add_gold(Player_1 *this, int gold) {
  this->money += gold;
  set_player_money_str(this->money, this->money_str);
}





/* Retourne le joueur 1 initialisé. */
/* GLOBAL */
Player_1 init_p1() {
  Player_1 p1;
  p1.chosen_friend = -1;
  p1.money = 2000;
  p1.last_free_gold = MLV_get_time();
  p1.score = 0;
  set_player_money_str(p1.money, p1.money_str);
  p1.life = 5;
  set_player_life_str(p1.life, p1.life_str);
  p1.is_deleting = false;
  return p1;
}





/* Retourne le joueur 2 initialisé. */
/* GLOBAL */
Player_2 init_p2() {
  Player_2 p2;
  p2.chosen_row = 0;
  p2.chosen_enemy = 0;
  p2.money = 2000;
  p2.last_free_gold = MLV_get_time();
  p2.score = 0;
  set_player_money_str(p2.money, p2.money_str);
  return p2;
}





/* Ajoute de l'or au joueur 2. */
/* GLOBAL */
void p2_create_free_gold(Player_2 *this) {
  this->money += QTY_FREE_GOLD_P2;
  set_player_money_str(this->money, this->money_str);
}





/* Achète un nouvel allié au joueur 1. */
/* GLOBAL */
void p1_buy_friend(Player_1 *this, Row *row, Friend_Spawner *spawner, int gridX, int gridY) {
  if (this->money >= spawner->price) {
    add_friend_in_row(row, spawner, gridX, gridY);
    this->money -= spawner->price;
    set_player_money_str(this->money, this->money_str);
  }
  this->chosen_friend = -1;
}





/* Achète un nouvel ennemie au joueur 2. */
/* GLOBAL */
void p2_buy_enemy(Player_2 *this, Row *row, Enemy_Spawner *spawner, int posX, int posY) {
  if (this->money >= spawner->price && row->nb_enemies < MAX_ENEMIES) {
    add_enemy_in_row(row, spawner, posX, posY);
    this->money -= spawner->price;
    set_player_money_str(this->money, this->money_str);
  }
}
