#include "../../headers/global_header.h"



void update_newgame_page(Newgame_Page *ngp, Sound_Manager *SM);



/* Récupère tous les paramètres de partie choisis par l'utilisateur et lance la partie. */
void prepare_launching(Newgame_Page *ngp, Sound_Manager *SM) {
  btn_value gamemode, difficulty;
  char *p1_name, *p2_name;
  gamemode = ngp->select_gamemode->value;
  difficulty = (gamemode == SOLO) ? ngp->select_difficulty->value : MEDIUM;
  p1_name = get_input_or_label_value(&ngp->p1_input, &ngp->p1_lbl);
  p2_name = (gamemode == MULTI) ? get_input_or_label_value(&ngp->p2_input, &ngp->p2_lbl) : "IA";

  if (strlen(p1_name) == 0) {
    p1_name = "Joueur 1";
  }
  if (strlen(p2_name) == 0) {
    p2_name = "Joueur 2";
  }
  launch_newgame(gamemode, difficulty, p1_name, p2_name, SM);
}



/* Selectionne le bouton survolé de la page et change les paramètres en fonction. */
static void select_hover_btn(Newgame_Page *ngp, Sound_Manager *SM) {
  switch (ngp->hover_btn->value) {
  case BACK:
    launch_main_page(ngp->width, ngp->height, SM);
    break;
  case SOLO:
    set_gamemode(ngp, SOLO);
    break;
  case MULTI:
    set_gamemode(ngp, MULTI);
    break;
  case EASY:
    set_difficulty(ngp, EASY);
    break;
  case MEDIUM:
    set_difficulty(ngp, MEDIUM);
    break;
  case HARD:
    set_difficulty(ngp, HARD);
    break;
  case LAUNCH:
    prepare_launching(ngp, SM);
  default:
    break;
  }
}



/* Met à jour le bouton survolé de la page. */
static void update_hover_btn(Newgame_Page *ngp, int posX, int posY) {
  Button *hover_btn = get_newgame_page_hover_btn(ngp, posX, posY);
  if (ngp->hover_btn != hover_btn) {
    unset_hover_btn(ngp->hover_btn);
    set_hover_btn(hover_btn);
    ngp->hover_btn = hover_btn;
  }
}



/* Met à jour l'affichage de la page. */
void update_newgame_page(Newgame_Page *ngp, Sound_Manager *SM) {
  Event_Manager em;
  int launch_time = MLV_get_time();

  /* Dessine la page de nouvelle partie. */
  draw_newgame_page(ngp);

  
  /* Première récupération des actions de l'utilisateur. */
  em = get_event();

  
  /* 
     Tant que:
       il ne s'est pas passé 200 milisecondes (pour actualiser les  inputs),
       l'utilisateur ne bouge pas,
       l'utilisateur n'appuis pas sur un bouton,
       l'utilisateur n'appuis pas sur la touche <Echap>,
       l'utilisateur ne valide pas le texte d'un input
     on récupère les actions de l'utilisateur.
  */
  while (MLV_get_time() < launch_time + 200 && em.event != MLV_MOUSE_MOTION && (em.event != MLV_MOUSE_BUTTON || em.btn_state != MLV_PRESSED || ngp->hover_btn == NULL) && (em.event != MLV_KEY || em.touch != MLV_KEYBOARD_ESCAPE) && em.event != MLV_INPUT_BOX) {
    em = get_event();
  }

  
  /* On purge la liste des evenements. */
  MLV_flush_event_queue();


  /* Gestion du clique sur un bouton. */
  if (em.event == MLV_MOUSE_BUTTON && em.btn_state == MLV_PRESSED && ngp->hover_btn != NULL) {
    select_hover_btn(ngp, SM);
    if (ngp->hover_btn->value != BACK && ngp->hover_btn->value != LAUNCH) {
      update_newgame_page(ngp, SM);
    }
  }
  
  /* Gestion de l'appuie sur la touche <Echap>. */
  else if (em.event == MLV_KEY && em.touch == MLV_KEYBOARD_ESCAPE) {
    launch_main_page(ngp->width, ngp->height, SM);
    return;
  }

  /* Gestion du mouvement de la souris. */
  else if (em.event == MLV_MOUSE_MOTION) {
    update_hover_btn(ngp, em.mouseX, em.mouseY);
    update_newgame_page(ngp, SM);
  }

  /* Gestion de la validation d'un input. */
  else if (em.event == MLV_INPUT_BOX) {
    set_player_name(ngp, em.input_box, em.text_input);
    update_newgame_page(ngp, SM);
  }

  /* Gestion du dépassement du délai d'actualisation. */
  else {
    update_newgame_page(ngp, SM);
  }
}



/* Lance la page pour créer une nouvelle partie. */
void launch_newgame_page(int width, int height, Sound_Manager *SM) {
  Newgame_Page ngp = init_newgame_page(width, height);

  /* Affectation des valeurs initiales. */
  set_gamemode(&ngp, SOLO);
  set_difficulty(&ngp, MEDIUM);
  set_hidden_lbl(&ngp.p1_lbl);
  set_hidden_lbl(&ngp.p2_lbl);
  
  update_newgame_page(&ngp, SM);
}
