#include "../../headers/global_header.h"



/* Lance l'effet sonore. */
void play_sound(Sound_Manager *SM, Sound *this) {
  if (!SM->sound_works) {
    return;
  }
  MLV_play_sound(this->sound, this->sound_level);
}



/* Lance la musique. */
void play_music(Sound_Manager *SM, Music *this) {
  if (!SM->sound_works) {
    return;
  }
  MLV_play_music(this->music, this->music_level, -1);
}



/* Initialise l'objet gestionnaire de son.  */
Sound_Manager init_SM() {
  Sound_Manager SM;

  /* Si l'audio n'est pas géré (WSL par exemple), on ne les jouera pas. */
  if(MLV_init_audio()){
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

  SM.game.music = MLV_load_music("resources/sounds/game_music.ogg");
  SM.game.music_level = 100;

  SM.menu.music = MLV_load_music("resources/sounds/menu_music.ogg");
  SM.menu.music_level = 100;

  return SM;
}



/* Libère tous les sons chargés. */
void free_SM(Sound_Manager *SM) {
  if (!SM->sound_works) {return;}
  
  MLV_stop_all_sounds();
  
  MLV_free_sound(SM->arrow.sound);
  MLV_free_sound(SM->big_monster_roar.sound);
  MLV_free_sound(SM->gold.sound);
  MLV_free_sound(SM->punch.sound);
  MLV_free_sound(SM->spear.sound);

  MLV_free_music(SM->game.music);
  MLV_free_music(SM->menu.music);
}
