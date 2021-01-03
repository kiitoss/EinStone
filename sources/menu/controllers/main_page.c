#include "../../headers/global_header.h"



/* Met à jour le bouton survolé de la page. */
static void update_hover_btn(Main_Page *mp, int posX, int posY) {
  Button *hover_btn = get_main_page_hover_btn(mp, posX, posY);
  if (mp->hover_btn != hover_btn) {
    unset_hover_btn(mp->hover_btn);
    set_hover_btn(hover_btn);
    mp->hover_btn = hover_btn;
  }
}



/* Change de page. */
void change_page(Main_Page *mp, Sound_Manager *SM) {
  switch (mp->hover_btn->value) {
  case NEWGAME:
    launch_newgame_page(mp->width, mp->height, SM);
    break;
  case RESUME:
    launch_resume_page(mp->width, mp->height, SM);
    break;
  case SCORE:
    launch_score_page(mp->width, mp->height, SM);
    break;
  default:
    break;
  } 
}



/* Met à jour l'affichage de la page. */
void update_main_page(Main_Page *mp, Sound_Manager *SM) {
  Event_Manager em;

  /* Dessine la page principale. */
  draw_main_page(mp);

  
  /* Première récupération des actions de l'utilisateur. */
  em = get_event();

  
  /* 
     Tant que l'utilisateur:
       ne bouge pas la souris,
       ne clique pas sur un bouton,
       n'appuie pas sur <Echap>
     on récupère les actions de l'utilisateur.
  */
  while (em.event != MLV_MOUSE_MOTION && (em.event != MLV_MOUSE_BUTTON || mp->hover_btn == NULL) && (em.event != MLV_KEY || em.touch != MLV_KEYBOARD_ESCAPE)) {
    em = get_event();
  }

  
  /* On purge la liste des evenements. */
  MLV_flush_event_queue();

  
  /*
    Gestion de l'action de l'utilisateur.
    Actualise la page uniquement dans le cas où l'utilisateur ne fait que bouger la souris.
  */
  if (em.event == MLV_MOUSE_BUTTON && mp->hover_btn != NULL) {
    change_page(mp, SM);
  }
  else if (em.event == MLV_KEY && em.touch == MLV_KEYBOARD_ESCAPE) {
    return;
  }
  else if (em.event == MLV_MOUSE_MOTION) {
    update_hover_btn(mp, em.mouseX, em.mouseY);
    update_main_page(mp, SM);
  }
}



/* Lance la page principale. */
void launch_main_page(int width, int height, Sound_Manager *SM) {
  Main_Page mp = init_main_page(width, height);

  /* Check si la musique du menu est en train d'être joué, la joue si ce n'est pas le cas. */
  if (!SM->menu_music_playing) {
    MLV_stop_music();
    play_music(SM, &SM->menu);
  }
    
  update_main_page(&mp, SM);
}
