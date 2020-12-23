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
  MLV_Sound *sound;
  
  if( MLV_init_audio() ){
    SM.sound_works = false;
    return SM;
  }

  SM.sound_works = true;
  
  SM.arrow.sound =  MLV_load_sound("resources/sounds/arrow_sound.ogg");
  SM.arrow.sound_level = 20;
  
  SM.big_monster_hurted.sound = MLV_load_sound("resources/sounds/big_monster_hurted_sound.ogg");
  SM.big_monster_hurted.sound_level = 20;
  
  SM.big_monster_roar.sound = MLV_load_sound("resources/sounds/big_monster_roar_sound.ogg");
  SM.big_monster_roar.sound_level = 20;
  
  SM.gold.sound = MLV_load_sound("resources/sounds/gold_sound.ogg");
  SM.gold.sound_level = 20;
  
  SM.punch.sound = MLV_load_sound("resources/sounds/punch_sound.ogg");
  SM.punch.sound_level = 20;
  
  SM.skeletton_walk.sound = MLV_load_sound("resources/sounds/skeletton_walk_sound.ogg");
  SM.skeletton_walk.sound_level = 20;
  
  SM.spear.sound = MLV_load_sound("resources/sounds/spear_sound.ogg");
  SM.spear.sound_level = 20;
  

  /*
  MLV_stop_all_sounds();
  MLV_free_sound( sound );
  MLV_free_audio();
  */
  return SM;
}
