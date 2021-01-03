#include "../../headers/global_header.h"



/* Met à jour le bouton  survolé de la page. */
static void update_hover_btn(Score_Page *sp, int posX, int posY) {
  Button *hover_btn = get_score_page_hover_btn(sp, posX, posY);
  if (sp->hover_btn != hover_btn) {
    unset_hover_btn(sp->hover_btn);
    set_hover_btn(hover_btn);
    sp->hover_btn = hover_btn;
  }
}



/* Met à jour l'affichage de la page. */
void update_score_page(Score_Page *sp, Sound_Manager *SM) {
  Event_Manager em;

  /* Dessine la page des scores. */
  draw_score_page(sp);

  /* Première récupération des actions de l'utilisateur. */
  em = get_event();

  /*
    Tant que l'utilisateur:
      ne bouge pas la souris,
      ne clique pas sur un bouton (un seul bouton sur cette page: BACK),
      n'appuie pas sur <Echap>
    on récupère les actions de l'utilisateur.
  */
  while (em.event != MLV_MOUSE_MOTION && (em.event != MLV_MOUSE_BUTTON || sp->hover_btn == NULL) && (em.event != MLV_KEY || em.touch != MLV_KEYBOARD_ESCAPE)) {
    em = get_event();
  }

  /* On purge la liste des evenements. */
  MLV_flush_event_queue();
  
  /* Gestion du mouvement de la souris. */
  if (em.event == MLV_MOUSE_MOTION) {
    update_hover_btn(sp, em.mouseX, em.mouseY);
    update_score_page(sp, SM);
  }

  /* Gestion du clique sur le bouton BACK ou de l'appuie sur la touche <Echap>. */
  else if ((em.event == MLV_KEY && em.touch == MLV_KEYBOARD_ESCAPE) || (em.event == MLV_MOUSE_BUTTON && sp->hover_btn != NULL)) {
    launch_main_page(sp->width, sp->height, SM);
  }
  else {
    update_score_page(sp, SM);
  }
}



/* Lance la page des meilleurs scores. */
void launch_score_page(int width, int height, Sound_Manager *SM) {
  GM_list_scores GMS;
  Score_Page sp;

  set_GMS(GMS);
  
  sp = init_score_page(width, height, GMS);
  draw_score_page(&sp);
  MLV_flush_event_queue();
  update_score_page(&sp, SM);
}
