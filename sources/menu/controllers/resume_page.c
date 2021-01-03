#include "../../headers/global_header.h"



/* Selectionne le bouton survolé de la page et change les paramètres en fonction. */
void select_hover_section(Resume_Page *rp) {
  unset_select_resume_section(rp->select_section);
  set_select_resume_section(rp->hover_section);
  rp->select_section = rp->hover_section;
}



/* Met à jour le bouton et la section survolés de la page. */
void update_hover_btn_and_section(Resume_Page *rp, int posX, int posY) {
  Button *hover_btn = get_resume_page_hover_btn(rp, posX, posY);
  Resume_Section *hover_section = get_resume_page_hover_section(rp, posX, posY);

  if (rp->hover_btn != hover_btn) {
    unset_hover_btn(rp->hover_btn);
    set_hover_btn(hover_btn);
    rp->hover_btn = hover_btn;
  }
  
  if (rp->hover_section != hover_section) {
    unset_hover_resume_section(rp->hover_section);
    set_hover_resume_section(hover_section);
    rp->hover_section = hover_section;
  }
}



/* Met à jour l'affichage de la page. */
void update_resume_page(Resume_Page *rp, Sound_Manager *SM) {
  Event_Manager em;

  /* Dessine la page des anciennes parties en cours. */
  draw_resume_page(rp);


  /* Première récupération des actions de l'utilisateur. */
  em = get_event();


  /*
    Tant que l'utilisateur:
      ne bouge pas la souris,
      ne clique pas sur un bouton ou une section,
      n'appuie pas sur <Echap>
    on récupère les actions de l'utilisateur.
  */
  while (em.event != MLV_MOUSE_MOTION && (em.event != MLV_MOUSE_BUTTON || (rp->hover_btn == NULL && rp->hover_section == NULL)) && (em.event != MLV_KEY || em.touch != MLV_KEYBOARD_ESCAPE)) {
    em = get_event();
  }

  
  /* On purge la liste des evenements. */
  MLV_flush_event_queue();

  /* Gestion du clique. */
  if (em.event == MLV_MOUSE_BUTTON && (rp->hover_btn != NULL || rp->hover_section != NULL)) {
    /* Clique sur une section. */
    if (rp->hover_section != NULL) {
      select_hover_section(rp);
    }
    /* Clique sur le bouton retour. */
    if (rp->hover_btn != NULL && rp->hover_btn->value == BACK) {
      launch_main_page(rp->width, rp->height, SM);
    }
    /* Clique sur le bouton de lancement de partie. */
    else if (rp->hover_btn != NULL && rp->hover_btn->value == LAUNCH && rp->select_section != NULL) {
      launch_resume(rp->select_section->GM, SM);
    }
    else {
      update_resume_page(rp, SM);
    }
  }

  /* Gestion de l'appuie sur la touche <Echap>. */
  else if (em.event == MLV_KEY && em.touch == MLV_KEYBOARD_ESCAPE) {
    launch_main_page(rp->width, rp->height, SM);
  }

  /* Gestion du mouvement de la souris. */
  else if (em.event == MLV_MOUSE_MOTION) {
    update_hover_btn_and_section(rp, em.mouseX, em.mouseY);
    update_resume_page(rp, SM);
  }
}



/* Lance la page pour continuer une ancienne partie. */
void launch_resume_page(int width, int height, Sound_Manager *SM) {
  GM_list_games GMG;
  Resume_Page rp;

  /* Récupère les anciennes parties. */
  set_GMG(GMG);
  
  rp = init_resume_page(width, height, GMG);
  
  update_resume_page(&rp, SM);
}
