/*
------------------------------------------------------------

MAKMAK from path: ./

------------------------------------------------------------
*/
/* controllers/mainPageC.c */
void launch_main_page(int width, int height);

/* controllers/newGamePageC.c */
void launch_newgame_page(int width, int height);

/* controllers/resumePageC.c */
void launch_resume_page(int width, int height);

/* controllers/scorePageC.c */
void launch_score_page(int width, int height);

/* models/mainPageM.c */
Button *get_main_page_hover_btn(mainPage *this, int posX, int posY);
mainPage init_main_page(int width, int height);

/* models/newgamePageM.c */
void set_player_name(newgamePage *this, MLV_Input_box *input_box, char *text_input);
void set_difficulty(newgamePage *this, menu_choice btn_value);
void set_gamemode(newgamePage *this, menu_choice btn_value);
newgamePage init_newgame_page(int width, int height);
Button *get_newgame_page_hover_btn(newgamePage *this, int posX, int posY);

/* models/resumePageM.c */
bool is_resumeSection_hover(resumeSection *this, int posX, int posY);
resumeSection get_new_resumeSection(Game_Manager *GM, Geometry container, char *font_path);
void set_hover_resume_section(resumeSection *this);
void unset_hover_resume_section(resumeSection *this);
void set_select_resume_section(resumeSection *this);
void unset_select_resume_section(resumeSection *this);
resumePage init_resume_page(int width, int height, GM_list_games GMG);
Button *get_resume_page_hover_btn(resumePage *this, int posX, int posY);
resumeSection *get_resume_page_hover_section(resumePage *this, int posX, int posY);

/* models/scorePageM.c */
Button *get_score_page_hover_btn(scorePage *this, int posX, int posY);
scoreSection get_new_scoreSection(Game_Manager *GM, Geometry container, char *font_path);
scorePage init_score_page(int width, int height, GM_list_scores GMS);

/* views/pageV.c */
Event_Manager get_event();
void draw_main_page(mainPage *mp);
void draw_newgame_page(newgamePage *ngp);
void draw_resume_section(resumeSection *this);
void draw_resume_page(resumePage *rp);
void draw_score_section(scoreSection *this);
void draw_score_page(scorePage *sp);

