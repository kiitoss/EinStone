#include "../gameHeader.h"
#include "../makhead.h"

void pause(Window *window, Game_Manager *GM) {
  MLV_Font *font = MLV_load_font("resources/font/Amatic-Bold.ttf", window->rectsize/2);
  Event_Manager em;
  em.event = MLV_NONE;
  
  char *play = "Play";
  char *save_quit = "Save and Quit";
  char *quit = "Quit";
  
  int line_size = window->rectsize / 5;
  int hover = 0;
  int last_hover = 0;
  int i;
  
  Geometry g[3];
  
  MLV_get_size_of_adapted_text_box_with_font(play, font, line_size, &g[0].width, &g[0].height);
  MLV_get_size_of_adapted_text_box_with_font(save_quit, font, line_size, &g[1].width, &g[1].height);
  MLV_get_size_of_adapted_text_box_with_font(quit, font, line_size, &g[2].width, &g[2].height);

  for (i=0; i<3; i++) {
    g[i].posX = (window->width - g[i].width) / 2;
    g[i].posY = (i+1)*(window->height/3 - g[i].height);
  }

  MLV_draw_filled_rectangle(0, 0, window->width, window->height, MLV_rgba(255, 255, 200, 200));
  draw_pause(hover, line_size, font, g, play, save_quit, quit);
  
  while ((em.event != MLV_KEY || em.touch != MLV_KEYBOARD_ESCAPE || em.btn_state != MLV_PRESSED) && (em.event != MLV_MOUSE_BUTTON || hover == 0)) {
    em = get_game_event();

    if (em.event == MLV_MOUSE_MOTION) {
      last_hover = hover;
      hover = 0;
      for (i=0; i<3; i++) {
	if (em.mouseX >= g[i].posX && em.mouseX <= g[i].posX + g[i].width && em.mouseY >= g[i].posY && em.mouseY <= g[i].posY + g[i].height) {
	  hover = i+1;
	}
      }
      if (hover != last_hover) {
	draw_pause(hover, line_size, font, g, play, save_quit, quit);
      }
    }
  }

  if (em.event == MLV_MOUSE_BUTTON) {
    if (hover == 1) {
      printf("continue\n");
    }
    else {
      MLV_free_font(font);
      GM->in_game = false;
    }
  }
}

void keyboard_action(Game_Manager *GM, MLV_Keyboard_button touch) {
  int pause_time;
  switch (touch) {
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
  case MLV_KEYBOARD_ESCAPE:
    pause_time = MLV_get_time();
    pause(&GM->window, GM);
    GM->p1.last_free_gold += MLV_get_time() - pause_time;
    GM->p2.last_free_gold += MLV_get_time() - pause_time;
    GM->last_refresh += MLV_get_time() - pause_time;
    break;
  case MLV_KEYBOARD_KP_ENTER:
  case MLV_KEYBOARD_RETURN:
    p2_buy_enemy(&GM->p2,
	      &GM->rows[GM->p2.chosen_row],
	      &GM->enemy_spawners[GM->p2.chosen_enemy],
	      GM->window.field.width,
	      GM->p2.chosen_row * GM->window.rectsize);
    break;
  default:
    break;
  }
}

void mouse_action(Game_Manager *GM, int mouseX, int mouseY) {
  int gridX, gridY;
  if (mouseX < GM->window.field.posX || mouseX > GM->window.field.posX + GM->window.field.width) {
    return;
  }
  gridX = (mouseX - GM->window.field.posX) / GM->window.rectsize;

  if (mouseY < GM->window.field.posY) {
    if (gridX > NB_FRIENDS || gridX == 0) {
      return;
    }
    GM->p1.chosen_friend = gridX - 1;
  }
  else if (mouseY < GM->window.field.posX + GM->window.field.height) {
    gridY = (mouseY - GM->window.field.posY) / GM->window.rectsize;
    if (GM->p1.chosen_friend != -1 && GM->rows[gridY].friends[gridX].id_friend == -1) {
      p1_buy_friend(&GM->p1,
		    &GM->rows[gridY],
		    &GM->friend_spawners[GM->p1.chosen_friend],
		    gridX,
		    gridY);
    }
    else {
      check_click_gold(GM, mouseX, mouseY);
    }
  }
}

void update_game(Game_Manager *GM, Texture_Manager *TM) {
  Event_Manager em;
  int random_row;
  em.event = MLV_NONE;
  em.btn_state = MLV_RELEASED;
  while (MLV_get_time() < GM->last_refresh + DELAY_REFRESH && (em.event != MLV_KEY || em.btn_state != MLV_PRESSED) && (em.event != MLV_MOUSE_BUTTON || em.btn_state != MLV_PRESSED)) {
    em = get_game_event();
  }
  if (MLV_get_time() >= GM->p1.last_free_gold + DELAY_FREE_GOLD_P1) {
    random_row = rand() % NB_ROWS;
    create_p1_free_gold(&GM->p1, &GM->rows[random_row], rand() % NB_COLUMNS, random_row);
  }
  if (MLV_get_time() >= GM->last_refresh + DELAY_REFRESH) {
    update_rows(GM, TM);
    GM->last_refresh = MLV_get_time();
  }
  else if (em.event == MLV_KEY) {
    keyboard_action(GM, em.touch);
  }
  else if (em.event == MLV_MOUSE_BUTTON) {
    mouse_action(GM, em.mouseX, em.mouseY);
  }
  if (GM->in_game) {
    draw_game(GM, TM);
    update_game(GM, TM);
  }
}

int main(int argc, char *argv[]) {
  unsigned int win_width, win_height;
  Texture_Manager TM;
  Game_Manager GM;
  Window window;
  menu_choice gamemode = MULTI;
  Sound_Manager SM = init_game_SM();

  play_sound(&SM, &SM.gold);
  
  MLV_get_desktop_size(&win_width, &win_height);

  window = init_window(win_width, win_height, gamemode);
  
  MLV_create_window("EinStone", "EinStone", window.width, window.height);

  TM = init_TM(window);
  GM = init_GM(&window, &TM, gamemode);

  /*
  MLV_enable_full_screen();
  */
  update_game(&GM, &TM);
  
  MLV_free_window();
  
  exit(0);
}
