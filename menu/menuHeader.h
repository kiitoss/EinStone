#include "../mainHeader.h"

#define MAX_BUTTONS 10
#define MAX_INPUTS 10
#define MAX_LABELS 10
#define MAX_SECTIONS 10

typedef struct {
  int width;
  int height;
  Label title_lbl;
  Button newgame_btn;
  Button resume_btn;
  Button score_btn;
  Button quit_btn;
  Button *hover_btn;
} mainPage;

typedef struct {
  int width;
  int height;
  Label title_lbl;
  Button solo_btn;
  Button multi_btn;
  Button easy_btn;
  Button medium_btn;
  Button hard_btn;
  Button launch_btn;
  Button back_btn;
  Input p1_input;
  Input p2_input;
  Label p1_lbl;
  Label p2_lbl;
  Button *hover_btn;
  Button *select_gamemode;
  Button *select_difficulty;
} newgamePage;

typedef struct {
  int width;
  int height;
  Label title_lbl;
  resumeSection sections[SAVED_GAMES];
  Button launch_btn;
  Button back_btn;
  Button *hover_btn;
  resumeSection *select_section;
  resumeSection *hover_section;
} resumePage;
