#include "../menuHeader.h"
#include "../makhead.h"

void update_resume_page(resumePage *rp) {
  while (true) {
  }
}

/* GLOBAL */
void launch_resume_page(int width, int height) {
  resumePage rp = init_resume_page(width, height);
  draw_resume_page(&rp);
  MLV_flush_event_queue();
  update_resume_page(&rp);
}
