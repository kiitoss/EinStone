#include "../gameHeader.h"
#include "../makhead.h"

void pause() {
  Event_Manager em;
  em.event = MLV_NONE;
  printf("PAUSE\n");
  while (em.event != MLV_KEY || em.touch != MLV_KEYBOARD_ESCAPE || em.btn_state != MLV_PRESSED) {
    em = get_game_event();
  }
  printf("not pause\n");
}

void keyboard_action(Game_Manager *GM, MLV_Keyboard_button touch) {
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
    pause();
    break;
  case MLV_KEYBOARD_KP_ENTER:
  case MLV_KEYBOARD_RETURN:
    buy_enemy(&GM->p2,
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
    if (GM->p1.chosen_friend == -1 || GM->rows[gridY].friends[gridX].id_friend != -1) {
      return;
    }
    
    buy_friend(&GM->p1,
	       &GM->rows[gridY],
	       &GM->friend_spawners[GM->p1.chosen_friend],
	       gridX,
	       gridY);
  }
}

void update_game(Game_Manager *GM, Texture_Manager *TM) {
  Event_Manager em;
  em.event = MLV_NONE;
  em.btn_state = MLV_RELEASED;
  while (MLV_get_time() < GM->last_refresh + DELAY_REFRESH && (em.event != MLV_KEY || em.btn_state != MLV_PRESSED) && (em.event != MLV_MOUSE_BUTTON || em.btn_state != MLV_PRESSED)) {
    em = get_game_event();
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
  draw_game(GM, TM);
  update_game(GM, TM);
}

int main(int argc, char *argv[]) {
  unsigned int win_width, win_height;
  Texture_Manager TM;
  Game_Manager GM;
  Window window;
  menu_choice gamemode = SOLO;
  
  MLV_get_desktop_size(&win_width, &win_height);

  window = init_window(win_width, win_height, gamemode);
  
  MLV_create_window("EinStone", "EinStone", window.width, window.height);

  TM = init_TM(window);
  GM = init_GM(&window, &TM, gamemode);


  MLV_enable_full_screen();
  
  update_game(&GM, &TM);
   
  MLV_wait_seconds(2);
  MLV_free_window();
  exit(0);
}
