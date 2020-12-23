#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
Sound_Manager init_game_SM() {
  Sound_Manager SM;
  MLV_Sound *sound;
  
  if( MLV_init_audio() ){
    SM.sound_works = false;
    return SM;
  }

  SM.sound_works = true;
  
  sound = MLV_load_sound("resources/sounds/gold.ogg");

  MLV_play_sound( sound, 1.0 );

  /*
  MLV_stop_all_sounds();
  MLV_free_sound( sound );
  MLV_free_audio();
  */
  return SM;
}
