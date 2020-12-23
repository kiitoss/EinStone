#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
Sound_Manager init_game_SM() {
  Sound_Manager SM;
  MLV_Sound *sound;
  MLV_Keyboard_button touche;
  
  if( MLV_init_audio() ){
    SM.sound_works = false;
    return SM;
  }

  SM.sound_works = true;
  
  sound = MLV_load_sound("resources/sounds/gold.ogg");

  touche=MLV_KEYBOARD_NONE;
  while( touche != MLV_KEYBOARD_ESCAPE ){
                MLV_wait_keyboard( &touche, NULL, NULL);
                MLV_play_sound( sound, 1.0 );
        }
  MLV_stop_all_sounds();
  MLV_free_sound( sound );
  MLV_free_audio();
  return SM;
}
