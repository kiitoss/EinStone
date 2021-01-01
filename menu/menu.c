#include "../headers/global_header.h"



/*
  Fonction première du programme:
    initialise les sons,
    créé la fenetre,
    joue la musique d'accueil,
    lance la page d'accueil du menu.
*/
int main(int argc, char *argv[]) {
  unsigned int win_width, win_height;
  int width, height;
  Sound_Manager SM = init_SM();
  
  printf("%d, %s\n", argc, *argv);
  
  MLV_get_desktop_size(&win_width, &win_height);
  width = 3 * win_width / 4;
  height = 3 * win_height / 4;
  
  if (FULL_SCREEN) {
    MLV_create_full_screen_window("EinStone", "EinStone", width, height);
  }
  else {
    MLV_create_window("EinStone", "EinStone", width, height);
  }
  
  
  play_music(&SM, &SM.menu);
  SM.menu_music_playing = true;
  
  launch_main_page(width, height, &SM);

  /* Libération des sons */
  free_SM(&SM);
  
  MLV_free_window();
  exit(0);
}
