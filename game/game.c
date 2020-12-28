#include "game_header.h"



void game_over(Window *window, Game_Manager *GM, gameOver *go) {
  Event_Manager em;
  Button *hover_btn;
  em.event = MLV_NONE;

  go->hover_btn = NULL;

  /* Mise en palce d'un filtre sur le jeu et dessin des boutons de l'écran de pause. */
  MLV_draw_filled_rectangle(0, 0, window->width, window->height, MLV_rgba(255, 255, 200, 200));
  draw_game_over_screen(go,GM);

  /* Attente du choix du joueur et mise en évidence du bouton survolé. */
  while (em.event != MLV_MOUSE_BUTTON || go->hover_btn == NULL) {
    em = get_game_event();

    if (em.event == MLV_MOUSE_MOTION) {
      hover_btn = NULL;
      
      if (is_btn_hover(&go->quit_btn, em.mouseX, em.mouseY)) {
	hover_btn = &go->quit_btn;
      }
      else if (is_btn_hover(&go->restart_btn, em.mouseX, em.mouseY)) {
	hover_btn = &go->restart_btn;
      }
      if (go->hover_btn != hover_btn) {
	unset_hover_btn(go->hover_btn);
	set_hover_btn(hover_btn);
	go->hover_btn = hover_btn;
	draw_game_over_screen(go,GM);
      }
    }
  }
  
  /* Action suivant le choix du joueur */
  if (em.event == MLV_MOUSE_BUTTON) {
    switch (go->hover_btn->value) {
    case PAUSE_QUIT:
      GM->in_game = false;
      break;
    case RESTART:
      launch_newgame(GM->gamemode,GM->difficulty,GM->p1.name,GM->p2.name);
      GM->in_game = true;
    default:break;
    }
  }
}

  

/* Mise en pause du jeu */
void pause(Window *window, Game_Manager *GM, pauseScreen *ps, int time) {
  Event_Manager em;
  Button *hover_btn;
  em.event = MLV_NONE;

  ps->hover_btn = NULL;

  /* Mise en palce d'un filtre sur le jeu et dessin des boutons de l'écran de pause. */
  MLV_draw_filled_rectangle(0, 0, window->width, window->height, MLV_rgba(255, 255, 200, 200));
  draw_pause_screen(ps);

  /* Attente du choix du joueur et mise en évidence du bouton survolé. */
  while ((em.event != MLV_KEY || (em.touch != MLV_KEYBOARD_ESCAPE && em.touch != MLV_KEYBOARD_p) || em.btn_state != MLV_PRESSED) && (em.event != MLV_MOUSE_BUTTON || ps->hover_btn == NULL)) {
    em = get_game_event();

    if (em.event == MLV_MOUSE_MOTION) {
      hover_btn = NULL;
      if (is_btn_hover(&ps->play_btn, em.mouseX, em.mouseY)) {
	hover_btn = &ps->play_btn;
      }
      else if (is_btn_hover(&ps->save_quit_btn, em.mouseX, em.mouseY)) {
	hover_btn = &ps->save_quit_btn;
      }
      else if (is_btn_hover(&ps->quit_btn, em.mouseX, em.mouseY)) {
	hover_btn = &ps->quit_btn;
      }

      if (ps->hover_btn != hover_btn) {
	unset_hover_btn(ps->hover_btn);
	set_hover_btn(hover_btn);
	ps->hover_btn = hover_btn;
	draw_pause_screen(ps);
      }
    }
  }

  /* Action suivant le choix du joueur */
  if (em.event == MLV_MOUSE_BUTTON) {
    switch (ps->hover_btn->value) {
    case PAUSE_PLAY:
      break;
    case PAUSE_SAVE_QUIT:
      save_game(GM, MLV_get_time() - time);
      GM->in_game = false;
      break;
    case PAUSE_QUIT:
      GM->in_game = false;
      break;
    default:
      break;
    }
  }
}





/* Action faisant suite à une action du clavier */
void keyboard_action(Game_Manager *GM, MLV_Keyboard_button touch, Texture_Manager *TM, int time) {
  int time_play;
  if (GM->gamemode != MULTI && touch != MLV_KEYBOARD_ESCAPE && touch != MLV_KEYBOARD_p) {return;}
  
  switch (touch) {
    /* Changement des choix du joueur 2 */
  case MLV_KEYBOARD_UP:
    GM->p2.chosen_row = (GM->p2.chosen_row - 1 + NB_ROWS) % NB_ROWS;
    break;
  case MLV_KEYBOARD_DOWN:
    GM->p2.chosen_row = (GM->p2.chosen_row + 1) % NB_ROWS;
    break;
  case MLV_KEYBOARD_LEFT:
    GM->p2.chosen_enemy = (GM->p2.chosen_enemy - 1 + NB_ENEMIES) % NB_ENEMIES;
    break;
  case MLV_KEYBOARD_RIGHT:
    GM->p2.chosen_enemy = (GM->p2.chosen_enemy + 1) % NB_ENEMIES;
    break;

    /* Achat de l'ennemie par le joueur 2*/
  case MLV_KEYBOARD_KP_ENTER:
  case MLV_KEYBOARD_RETURN:
    p2_buy_enemy(&GM->p2,
		 &GM->rows[GM->p2.chosen_row],
		 &GM->enemy_spawners[GM->p2.chosen_enemy],
		 GM->window.field.width,
		 GM->p2.chosen_row * GM->window.rectsize);
    break;

    /* Pause dans le jeu */
  case MLV_KEYBOARD_ESCAPE:
  case MLV_KEYBOARD_p:
    pause(&GM->window, GM, &TM->pause_screen, time);
    time_play = MLV_get_time();
    GM->p1.last_free_gold += time_play - time;
    GM->p2.last_free_gold += time_play - time;
    GM->last_refresh += time_play - time;
    GM->duration -= time_play - time;
    break;
 
  default:
    break;
  }
}




/* Action faisant suite à une action de la souris. */
void mouse_action(Game_Manager *GM, int mouseX, int mouseY) {
  int gridX, gridY;

  if (GM->p1.chosen_friend == -1 && GM->p1.is_deleting == false) {
    check_click_gold(GM, mouseX, mouseY);
  }

  /* Clique à gauche, à droite, ou en dessous du terrain. */
  if (mouseX < GM->window.field.posX || mouseX > GM->window.field.posX + GM->window.field.width || mouseY > GM->window.field.posY + GM->window.field.height) {
    GM->p1.chosen_friend = -1;
    GM->p1.is_deleting = false;
    return;
  }

  
  gridX = (mouseX - GM->window.field.posX) / GM->window.rectsize;

  /* Clique dans le spawner allié. */
  if (mouseY < GM->window.friend_spawner.posY + GM->window.friend_spawner.height) {

    /* Colonne stats du joueur 1. */
    if (gridX == 0) {
      GM->p1.chosen_friend = -1;
      GM->p1.is_deleting = false;
    }
    
    /* Colonne suppression. */
    else if (gridX == NB_COLUMNS-1) {
      GM->p1.chosen_friend = -1;
      GM->p1.is_deleting = !GM->p1.is_deleting;
    }

    /* La colonnes d'un des spawners alliés. */
    else if (gridX <= NB_FRIENDS) {
      if (GM->p1.chosen_friend == gridX - 1) {
	GM->p1.chosen_friend = -1;
      }
      else {	
	GM->p1.chosen_friend = gridX - 1;
	GM->p1.is_deleting = false;
      }
    }
    
    else {
      GM->p1.chosen_friend = -1;
      GM->p1.is_deleting = false;
    }

    return;
  }

  
  /* Clique sur le terrain. */
  gridY = (mouseY - GM->window.field.posY) / GM->window.rectsize;

  /* Si le joueur 1 est en cours de suppression. */
  if (GM->p1.is_deleting) {
    if (is_friend(&GM->rows[gridY].friends[gridX])) {
      remove_friend_from_row(&GM->rows[gridY].friends[gridX]);
    }
    GM->p1.is_deleting = false;
    return;
  }

  /* Si le joueur 1 achète un joueur. */
  if (GM->p1.chosen_friend != -1) {
    if (is_friend(&GM->rows[gridY].friends[gridX])) {
      GM->p1.chosen_friend = -1;
      return;
    }
    
    p1_buy_friend(&GM->p1,
		  &GM->rows[gridY],
		  &GM->friend_spawners[GM->p1.chosen_friend],
		  gridX,
		  gridY);
    
  }
}





/* Met à jour le jeu. */
void update_game(Game_Manager *GM, Texture_Manager *TM, Sound_Manager *SM) {
  Event_Manager em;
  int random_row, random_column;
  int time, i;
  em.event = MLV_NONE;
  em.btn_state = MLV_RELEASED;
  em.touch = MLV_NONE;
  
  while (MLV_get_time() < GM->last_refresh + DELAY_REFRESH && (em.event != MLV_KEY || em.btn_state != MLV_PRESSED) && (em.event != MLV_MOUSE_BUTTON || em.btn_state != MLV_PRESSED)) {
    em = get_game_event();
  }

  time = MLV_get_time();

  /* Affichage du Game Over */
  if(GM->p1.life == 0){
    remove_saved_game(GM->id);
    if (GM->gamemode == SOLO) {
      save_score(GM, MLV_get_time() - time);
    }
    game_over(&GM->window,GM,&TM->game_over_screen);
  }
  
  /* Création d'or pour le joueur 1. */
  if (time >= GM->p1.last_free_gold + DELAY_FREE_GOLD_P1) {
    random_row = rand() % NB_ROWS;
    random_column = rand() % NB_COLUMNS;
    create_new_gold(&GM->rows[random_row], random_column, random_row, SM);
    GM->p1.last_free_gold = time;
  }

  /* Création d'or pour le joueur 2 / IA. */
  if (time >+ GM->p2.last_free_gold + DELAY_FREE_GOLD_P2) {
    p2_create_free_gold(&GM->p2, GM->difficulty, GM->gamemode);
    GM->p2.last_free_gold = time;
    if (GM->gamemode == SOLO) {
      /* Mise à jour de l'IA. */
      update_IA(GM);
    }
  }

  /* Mise à jour des lignes du terrain de jeu. */
  if (time >= GM->last_refresh + DELAY_REFRESH) {
    for (i=0; i<NB_ROWS; i++) {
      update_row(&GM->rows[i], GM, SM);
    }
    GM->last_refresh = time;
  }

  /* Gère l'action du clavier et de la souris. */
  if ((em.event == MLV_KEY && GM->gamemode == MULTI) || em.touch == MLV_KEYBOARD_ESCAPE || em.touch == MLV_KEYBOARD_p) {
    keyboard_action(GM, em.touch, TM, time);
  }
  else if (em.event == MLV_MOUSE_BUTTON) {
    mouse_action(GM, em.mouseX, em.mouseY);
  }

  /* S'auto-appel tant que le jeu continue. */
  if (GM->in_game) {
    draw_game(GM, TM, time);
    update_game(GM, TM, SM);
  }
}





/* Libère des images et des sons du jeu avant de retourner au menu */
/* GLOBAL */
void quit_game(Game_Manager *GM, Texture_Manager *TM, Sound_Manager *SM) {
  /* Libération des sons */
  free_SM(SM);

  /* Libération des images. */
  free_TM(TM);

  MLV_free_font(TM->font);

  
  MLV_change_window_size(GM->window.width/2, GM->window.height/2);
  
  launch_main_page(GM->window.width/2, GM->window.height/2);
  
  MLV_free_window();
  
  exit(0);
}





/* Lancement d'une nouvelle partie */
/* GLOBAL */
void launch_newgame(btn_value gamemode, btn_value difficulty, char *p1_name, char *p2_name) {
  Texture_Manager TM;
  Game_Manager GM;
  Window window;
  Sound_Manager SM = init_game_SM();
  unsigned int win_width, win_height;
  
  printf("%d, %d, %s, %s\n", gamemode, difficulty, p1_name, p2_name);
  
  MLV_get_desktop_size(&win_width, &win_height);
  
  window = init_window(win_width, win_height, gamemode);
  
  MLV_change_window_size(window.width, window.height);

  TM = init_TM(window);
  GM = init_GM(&window, &TM, gamemode, difficulty, p1_name, p2_name);

  if (GM.gamemode == SOLO) {
    init_IA(&GM);
  }

  update_game(&GM, &TM, &SM);

  quit_game(&GM, &TM, &SM);
}





/* Reset les animations des spawners, des alliés et des ennemies. */
void reset_entities_animations(Game_Manager *GM, Texture_Manager *TM, Window *window) {
  int i, j;
  
  for (i=0; i<NB_FRIENDS; i++) {
    set_friend_spawner_animations(&GM->friend_spawners[i], TM, window, i);
  }
  
  for (i=0; i<NB_ENEMIES; i++) {
    set_enemy_spawner_animations(&GM->enemy_spawners[i], TM, window, i);
  }

  
  for (i=0; i<NB_ROWS; i++) {
    for (j=0; j<NB_COLUMNS; j++) {
      if (is_friend(&(GM->rows[i].friends[j]))) {
	reset_friend_animations(&GM->rows[i].friends[j], &GM->friend_spawners[GM->rows[i].friends[j].id_friend-1]);
      }
    }
    
    for (j=0; j<GM->rows[i].nb_enemies; j++) {
      reset_enemy_animations(&GM->rows[i].enemies[j], &GM->enemy_spawners[GM->rows[i].enemies[j].id_enemy-1]);
    }
  }
}





/* Lancement d'une ancienne partie */
/* GLOBAL */
void launch_resume(Game_Manager *GM) {
  Texture_Manager TM;
  Window window;
  Sound_Manager SM = init_game_SM();
  unsigned int win_width, win_height;
  
  MLV_get_desktop_size(&win_width, &win_height);

  window = init_window(win_width, win_height, GM->gamemode);
  
  MLV_change_window_size(window.width, window.height);
  
  TM = init_TM(window);

  reset_entities_animations(GM, &TM, &window);
  
  GM->window = window;
  GM->last_refresh = MLV_get_time();
  GM->in_game = true;
  GM->duration -= MLV_get_time();
  
  init_IA(GM);  
  
  update_game(GM, &TM, &SM);

  quit_game(GM, &TM, &SM);
}
