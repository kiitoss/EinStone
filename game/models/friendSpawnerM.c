#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
Friend_Spawner init_FS(int index_friend, Texture_Manager *TM, Window *window) {
  Friend_Spawner FS;
  int row_animation_ability, first_frame_ability, last_frame_ability, time_ability;
  switch (index_friend) {
  case 0:
    FS.id_friend = 1;
    FS.ability = MONEY;
    FS.life = 50;
    FS.attack = 0;
    FS.price = 50;
    FS.delay_ability = 1000;
    FS.delay_frame_ability = 0;
    FS.range = 0;
    break;
  case 1:
    FS.id_friend = 2;
    FS.ability = ATTACK;
    FS.life = 100;
    FS.attack = 35;
    FS.price = 100;
    FS.delay_ability = 100;
    FS.delay_frame_ability = 0;
    FS.range = window->rectsize*2;
    break;
  case 2:
    FS.id_friend = 3;
    FS.ability = DEFENSE;
    FS.life = 200;
    FS.attack = 20;
    FS.price = 75;
    FS.delay_ability = 70;
    FS.delay_frame_ability = 0;
    FS.range = window->rectsize*1;
    break;
  default:
    printf("--> Maximum friends dépassé !\n");
    exit(1);
    break;
  }
  
  sprintf(FS.price_str, "%d", FS.price);
  
  switch (FS.ability) {
  case MONEY:
    row_animation_ability = 3;
    first_frame_ability = 0;
    last_frame_ability = 7;
    time_ability = 10;
    break;
  case ATTACK:
    row_animation_ability = 19;
    first_frame_ability = 0;
    last_frame_ability = 13;
    time_ability = 8;
    break;
  case DEFENSE:
    row_animation_ability = 0;
    first_frame_ability = 8;
    last_frame_ability = 10;
    time_ability = 10;
    break;
  default:
    row_animation_ability = 3;
    first_frame_ability = 0;
    last_frame_ability = 2;
    time_ability = 20;
    break;
  }
  FS.animation_passive = get_animation(TM->friend_spawners_sprites[index_friend], window->rectsize, 3, 0, 2, 20);
  FS.animation_ability = get_animation(TM->friend_spawners_sprites[index_friend], window->rectsize, row_animation_ability, first_frame_ability, last_frame_ability, time_ability);
  return FS;
}
