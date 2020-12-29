#include "../../headers/global_header.h"






/* Convertit le montant de l'or (int) en string. */
/* GLOBAL */
void set_player_money_str(long money, char money_str[10]) {
  sprintf(money_str, "%ld", money);
}





/* Ajoute un montant au total d'or du joueur 1. */
/* GLOBAL */
void p1_add_gold(Player_1 *this, int gold) {
  this->money += gold;
  set_player_money_str(this->money, this->money_str);
}





/* Ajoute de l'or au joueur 2. */
/* GLOBAL */
void p2_create_free_gold(Player_2 *this, btn_value difficulty) {
  /* min est le nombre de minutes depuis le lancement de partie. */
  int min = MLV_get_time() / 1000 / 60;
  int expo = EXPO_GOLD_IA;
  int amount;

  if (difficulty == EASY) {
    expo /= 2;
  }
  else if (difficulty == HARD) {
    expo *= 2;
  }
  /* amount: Un = U(n-1) + n*expo = U0 + n*(n+1)/2 * expo */
  amount = QTY_FREE_GOLD_P2 + (min*(min+1)/2)*expo;
  
  this->money += amount;
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
