#include "../menuHeader.h"
#include "../makhead.h"

void update_hover_btn(mainPage *mp, int posX, int posY) {
  Button *hover_btn = get_main_page_hover_btn(mp, posX, posY);
  if (mp->hover_btn != hover_btn) {
    if (mp->hover_btn != NULL) {
      unset_hover_btn(mp->hover_btn);
    }
    
    if (hover_btn != NULL) {
      set_hover_btn(hover_btn);
    }

    mp->hover_btn = hover_btn;
    draw_main_page(mp);
  }
}

void update_main_page(mainPage *mp) {
  Event_Manager em;
  draw_main_page(mp);
  em = get_event();
  while (em.event != MLV_MOUSE_MOTION && (em.event != MLV_MOUSE_BUTTON || em.btn_state != MLV_PRESSED)) {
    em = get_event();
  }
  if (em.event == MLV_MOUSE_BUTTON) {
    printf("clique\n");
  }
  else {
    update_hover_btn(mp, em.mouseX, em.mouseY);
  }
  update_main_page(mp);
}

/* GLOBAL */
void launch_main_page(int width, int height) {
  mainPage mp = init_main_page(width, height);
  draw_main_page(&mp);
  update_main_page(&mp);
}

int main(int argc, char *argv[]) {
  int width, height;
  width = 700;
  height = 700;
  MLV_create_window("TEST", "TEST", width, height);
  launch_main_page(width, height);
  MLV_wait_seconds(2);
  MLV_free_window();
  exit(0);
}
