#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
void play_sound(Sound_Manager *SM, Sound *this) {
  if (!SM->sound_works) {
    return;
  }
  MLV_play_sound(this->sound, this->sound_level);
}

/* GLOBAL */
Sound_Manager init_game_SM() {
  Sound_Manager SM;
  
  if( MLV_init_audio() ){
    SM.sound_works = false;
    return SM;
  }

  SM.sound_works = true;
  
  SM.arrow.sound =  MLV_load_sound("resources/sounds/arrow_sound.ogg");
  SM.arrow.sound_level = 100;
  
  SM.big_monster_roar.sound = MLV_load_sound("resources/sounds/big_monster_roar_sound.ogg");
  SM.big_monster_roar.sound_level = 100;
  
  SM.gold.sound = MLV_load_sound("resources/sounds/gold_sound.ogg");
  SM.gold.sound_level = 100;
  
  SM.punch.sound = MLV_load_sound("resources/sounds/punch_sound.ogg");
  SM.punch.sound_level = 100;
  
  SM.spear.sound = MLV_load_sound("resources/sounds/spear_sound.ogg");
  SM.spear.sound_level = 100;
  
  return SM;
}
