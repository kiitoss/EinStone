#include "../menuHeader.h"
#include "../makhead.h"

void select_hover_btn_or_section(resumePage *rp) {
  unset_select_resume_section(rp->select_section);
  set_select_resume_section(rp->hover_section);
  rp->select_section = rp->hover_section;
}

void update_hover_btn_and_section(resumePage *rp, int posX, int posY) {
  Button *hover_btn = get_resume_page_hover_btn(rp, posX, posY);
  resumeSection *hover_section = get_resume_page_hover_section(rp, posX, posY);

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

void update_resume_page(resumePage *rp) {
  Event_Manager em;
  draw_resume_page(rp);
  em = get_event();
  while (em.event != MLV_MOUSE_MOTION && (em.event != MLV_MOUSE_BUTTON || (rp->hover_btn == NULL && rp->hover_section == NULL)) && (em.event != MLV_KEY || em.touch != MLV_KEYBOARD_ESCAPE)) {
    em = get_event();
  }
  if (em.event == MLV_MOUSE_BUTTON && (rp->hover_btn != NULL || rp->hover_section != NULL)) {
    select_hover_btn_or_section(rp);
    if (rp->hover_btn != NULL && rp->hover_btn->value == BACK) {
      launch_main_page(rp->width, rp->height);
    }
    else {
      update_resume_page(rp);
    }
  }
  else if (em.event == MLV_KEY && em.touch == MLV_KEYBOARD_ESCAPE) {
    launch_main_page(rp->width, rp->height);
  }
  else if (em.event == MLV_MOUSE_MOTION) {
    update_hover_btn_and_section(rp, em.mouseX, em.mouseY);
    update_resume_page(rp);
  }
}

/* GLOBAL */
void launch_resume_page(int width, int height) {
  GM_List GM_list;
  resumePage rp;
  int i;

  FILE *data = fopen("resources/data.bin", "rb");
  if (data == NULL) {
    printf("--> Fichier de données introuvable.\n");
  }
  else {
    for (i=0; i<SAVED_GAMES; i++) {
      if (!fread(&GM_list[i], sizeof(Game_Manager), 1, data)) {
	printf("Erreur lors de la lecture des scores.\n");
      }
    }
  }
  fclose(data);

  /*
  for (i=0; i<SAVED_GAMES; i++) {
    printf("id: %d\n", GM_list[i].id);
  }
  */
  rp = init_resume_page(width, height);
  draw_resume_page(&rp);
  MLV_flush_event_queue();
  update_resume_page(&rp);
}
