#include "../mainHeader.h"
#include "makhead.h"





/* Sauvegarde la partie en cours */
void save_game(Game_Manager *GM) {
  GM_List GM_list;
  int i;
  bool is_free_id;
  FILE *f = fopen("resources/data.bin", "rb");
 
  if (f == NULL) {
    printf("--> fichier de sauvegarde introuvable.\n");
    return;
  }

  /* Lecture des anciennes sauvegardes dans la liste des parties */
  for (i=0; i<SAVED_GAMES; i++) {
    if (!fread(&GM_list[i], sizeof(Game_Manager), 1, f)) {
      printf("Erreur lors de l'écriture des scores.\n");
    }
  }

  /* Incrémentation des sauvegardes */
  for (i=SAVED_GAMES-1; i>0; i--) {
    GM_list[i] = GM_list[i-1];
  }

  /* Attribution d'un id à la partie en cours */
  if (GM->id == 0) {
    GM->id = 1;
    is_free_id = false;
    while (!is_free_id) {
      is_free_id = true;
      for (i=1; i<SAVED_GAMES; i++) {
	if (GM_list[i].id == GM->id) {
	  GM->id++;
	  is_free_id = false;
	  break;
	}
      }
    }
  }

  GM->duration += MLV_get_time();

  /* Insertion de la partie en cours dans la liste des parties */
  GM_list[0] = *GM;
  fclose(f);

  /* Ecriture de la liste des parties sauvegardées */
  f = fopen("resources/data.bin", "wb");
  for (i=0; i<SAVED_GAMES; i++) {
    fwrite(&GM_list[i], sizeof(Game_Manager), 1 ,f);
  }

  fclose(f);
}





/* Mise en pause du jeu */
void pause(Window *window, Game_Manager *GM, pauseScreen *ps) {
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
      save_game(GM);
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
void keyboard_action(Game_Manager *GM, MLV_Keyboard_button touch, Texture_Manager *TM) {
  int pause_time, time;
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
    pause_time = MLV_get_time();
    pause(&GM->window, GM, &TM->pause_screen);
    time = MLV_get_time();
    GM->p1.last_free_gold += time - pause_time;
    GM->p2.last_free_gold += time - pause_time;
    GM->last_refresh += time - pause_time;
    GM->duration -= time - pause_time;
    break;
 
  default:
    break;
  }
}





/* Compare la position de la souris et celles des pièces d'or sur le terrain. */
void check_click_gold(Game_Manager *GM, int mouseX, int mouseY) {
  int i, j;
  Gold *g;
  bool get = false;

  mouseX -= GM->window.field.posX;
  mouseY -= GM->window.field.posY;
  
  for (i=0; i<NB_ROWS; i++) {
    for (j=0; j<GM->rows[i].nb_golds; j++) {
      g = &GM->rows[i].golds[j];
      if (is_clicked_gold(g, mouseX, mouseY)) {
	p1_add_gold(&GM->p1, g->value);
	remove_gold_from_row(&GM->rows[i], j);
	get = true;
	break;
      }
    }
    if (get) {break;}
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

  /* Mise à jour de l'IA. */
  update_IA(GM);
  
  /* Création d'or pour le joueur 1. */
  if (time >= GM->p1.last_free_gold + DELAY_FREE_GOLD_P1) {
    random_row = rand() % NB_ROWS;
    random_column = rand() % NB_COLUMNS;
    create_new_gold(&GM->rows[random_row], random_column, random_row, SM);
    GM->p1.last_free_gold = time;
  }

  /* Création d'or pour le joueur 2 / IA. */
  if (time >+ GM->p2.last_free_gold + DELAY_FREE_GOLD_P2) {
    p2_create_free_gold(&GM->p2);
    GM->p2.last_free_gold = time;
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
    keyboard_action(GM, em.touch, TM);
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
void launch_newgame(menu_choice gamemode, menu_choice difficulty, char *p1_name, char *p2_name) {
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
  GM = init_GM(&window, &TM, gamemode);
  
  update_game(&GM, &TM, &SM);

  quit_game(&GM, &TM, &SM);
}
