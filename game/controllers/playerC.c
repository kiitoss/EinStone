#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
void update_player_money_str(int money, char money_str[10]) {
}

/* GLOBAL */
void buy_friend(Player_1 *this, Row *row, Friend_Spawner *spawner, int gridX, int gridY) {
  this->money = spawner->price + 1000;
  if (this->money >= spawner->price) {
    add_friend_in_row(row, spawner, gridX, gridY);
    this->money -= spawner->price;
    update_player_money_str(this->money, this->money_str);
  }
  this->chosen_friend = -1;
}


/* GLOBAL */
void buy_enemy(Player_2 *this, Row *row, Enemy_Spawner *spawner, int posX, int posY) {
  this->money = spawner->price + 1000;
  if (this->money >= spawner->price) {
    add_enemy_in_row(row, spawner, posX, posY);
    this->money -= spawner->price;
    update_player_money_str(this->money, this->money_str);
  }
}
