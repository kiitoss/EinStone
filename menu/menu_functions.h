/* controllers/main_page.c */
void launch_main_page(int width, int height);

/* controllers/newgame_page.c */
void launch_newgame_page(int width, int height);

/* controllers/resume_page.c */
void launch_resume_page(int width, int height);

/* controllers/score_page.c */
void launch_score_page(int width, int height);

/* methods/meth_main_page.c */
Button *get_main_page_hover_btn(Main_Page *this, int posX, int posY);
Main_Page init_main_page(int width, int height);

/* methods/meth_newgame_page.c */
void set_player_name(Newgame_Page *this, MLV_Input_box *input_box, char *text_input);
void set_difficulty(Newgame_Page *this, btn_value btn_value);
void set_gamemode(Newgame_Page *this, btn_value btn_value);
Newgame_Page init_newgame_page(int width, int height);
Button *get_newgame_page_hover_btn(Newgame_Page *this, int posX, int posY);

/* methods/meth_resume_page.c */
bool is_resume_section_hover(Resume_Section *this, int posX, int posY);
Resume_Section get_new_resume_section(Game_Manager *GM, Geometry container, char *font_path);
void set_hover_resume_section(Resume_Section *this);
void unset_hover_resume_section(Resume_Section *this);
void set_select_resume_section(Resume_Section *this);
void unset_select_resume_section(Resume_Section *this);
Resume_Page init_resume_page(int width, int height, GM_list_games GMG);
Button *get_resume_page_hover_btn(Resume_Page *this, int posX, int posY);
Resume_Section *get_resume_page_hover_section(Resume_Page *this, int posX, int posY);

/* methods/meth_score_page.c */
Button *get_score_page_hover_btn(Score_Page *this, int posX, int posY);
Score_Section get_new_score_section(Game_Manager *GM, Geometry container, char *font_path);
Score_Page init_score_page(int width, int height, GM_list_scores GMS);

/* views/draw_menu.c */
Event_Manager get_event();
void draw_main_page(Main_Page *mp);
void draw_newgame_page(Newgame_Page *ngp);
void draw_resume_section(Resume_Section *this);
void draw_resume_page(Resume_Page *rp);
void draw_score_section(Score_Section *this);
void draw_score_page(Score_Page *sp);

