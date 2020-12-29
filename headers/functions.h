/* menu/views/draw_menu.c */
Event_Manager get_event();
void draw_main_page(Main_Page *mp);
void draw_newgame_page(Newgame_Page *ngp);
void draw_resume_section(Resume_Section *this);
void draw_resume_page(Resume_Page *rp);
void draw_score_section(Score_Section *this);
void draw_score_page(Score_Page *sp);

/* menu/methods/meth_score_page.c */
Button *get_score_page_hover_btn(Score_Page *this, int posX, int posY);
Score_Section get_new_score_section(Game_Manager *GM, Geometry container, char *font_path);
Score_Page init_score_page(int width, int height, GM_list_scores GMS);

/* menu/methods/meth_main_page.c */
Button *get_main_page_hover_btn(Main_Page *this, int posX, int posY);
Main_Page init_main_page(int width, int height);

/* menu/methods/meth_resume_page.c */
bool is_resume_section_hover(Resume_Section *this, int posX, int posY);
Resume_Section get_new_resume_section(Game_Manager *GM, Geometry container, char *font_path);
void set_hover_resume_section(Resume_Section *this);
void unset_hover_resume_section(Resume_Section *this);
void set_select_resume_section(Resume_Section *this);
void unset_select_resume_section(Resume_Section *this);
Resume_Page init_resume_page(int width, int height, GM_list_games GMG);
Button *get_resume_page_hover_btn(Resume_Page *this, int posX, int posY);
Resume_Section *get_resume_page_hover_section(Resume_Page *this, int posX, int posY);

/* menu/methods/meth_newgame_page.c */
void set_player_name(Newgame_Page *this, MLV_Input_box *input_box, char *text_input);
void set_difficulty(Newgame_Page *this, btn_value btn_value);
void set_gamemode(Newgame_Page *this, btn_value btn_value);
Newgame_Page init_newgame_page(int width, int height);
Button *get_newgame_page_hover_btn(Newgame_Page *this, int posX, int posY);

/* menu/controllers/main_page.c */
void launch_main_page(int width, int height, Sound_Manager *SM);

/* menu/controllers/resume_page.c */
void launch_resume_page(int width, int height, Sound_Manager *SM);

/* menu/controllers/newgame_page.c */
void launch_newgame_page(int width, int height, Sound_Manager *SM);

/* menu/controllers/score_page.c */
void launch_score_page(int width, int height, Sound_Manager *SM);

/* game/views/draw_object.c */
void draw_row(Row *r, Window *window, Texture_Manager *TM);

/* game/views/draw_game.c */
void draw_game(Game_Manager *GM, Texture_Manager *TM, int time);
Event_Manager get_game_event();

/* game/views/draw_window.c */
void draw_time(int time, Window *window);
void draw_pause_screen(Pause_Screen *this);
void draw_game_over_screen(Game_Over *this,Game_Manager *GM);
void draw_window(Game_Manager *GM, Texture_Manager *TM);

/* game/controllers/IA.c */
void update_IA(Game_Manager *GM);

/* game/controllers/row.c */
void remove_friend_from_row(Friend *f);
void remove_gold_from_row(Row *this, int index_gold);
void remove_shot_from_row(Row *this, int index_shot);
void remove_enemy_from_row(Row *this, int index_enemy, Sound_Manager *SM, int *p1_score);
void add_friend_in_row(Row *this, Friend_Spawner *spawner, int gridX, int gridY);
void add_enemy_in_row(Row *this, Enemy_Spawner *spawner, int posX, int posY);
void update_row(Row *this, Game_Manager *GM, Sound_Manager *SM);

/* game/controllers/player.c */
void set_player_money_str(long money, char money_str[10]);
void p1_add_gold(Player_1 *this, int gold);
void p2_create_free_gold(Player_2 *this, btn_value difficulty);
void p1_buy_friend(Player_1 *this, Row *row, Friend_Spawner *spawner, int gridX, int gridY);
void p2_buy_enemy(Player_2 *this, Row *row, Enemy_Spawner *spawner, int posX, int posY);

/* game/controllers/pop.c */
void check_click_gold(Game_Manager *GM, int mouseX, int mouseY);
Shot get_new_shot(int posX, int posY, int rectsize, int attack);
bool is_clicked_gold(Gold *this, int mouseX, int mouseY);
Gold get_new_gold(int centerX, int centerY, int rectsize);
void update_gold(Gold *this);
void move_shot(Shot *this);
void create_new_gold(Row *row, int gridX, int gridY, Sound_Manager *SM);
void create_new_shot(Row *row, int gridX, int gridY, int attack, Sound_Manager *SM);

/* game/controllers/enemy.c */
Enemy get_new_enemy(Enemy_Spawner *spawner, int posX, int posY);
void set_enemy_animation(Enemy *this, MLV_Animation_player *animation);
void update_enemy(Enemy *this, Row *row, Sound_Manager *SM);
void reset_enemy_animations(Enemy *this, Enemy_Spawner *spawner);

/* game/controllers/friend.c */
Friend get_new_friend(Friend_Spawner *spawner, int posX, int posY);
bool is_friend(Friend *this);
void set_friend_animation(Friend *this, MLV_Animation_player *animation);
void update_friend(Friend *this, Row *row, Sound_Manager *SM, int *p1_score);
void reset_friend_animations(Friend *this, Friend_Spawner *spawner);

/* game/initializers/init_SM.c */
void play_sound(Sound_Manager *SM, Sound *this);
void play_music(Sound_Manager *SM, Music *this);
Sound_Manager init_SM();
void free_SM(Sound_Manager *SM);

/* game/initializers/init_IA.c */
void init_IA(Game_Manager *GM);

/* game/initializers/init_window.c */
Window init_window(unsigned int win_width, unsigned int win_height, btn_value gamemode);

/* game/initializers/init_GM.c */
Player_1 init_p1(char *p1_name);
Player_2 init_p2(char *p2_name);
Row init_row(int rectsize);
Game_Manager init_GM(Window *window, Texture_Manager *TM, btn_value gamemode,btn_value difficulty,char *p1_name,char *p2_name);

/* game/initializers/init_spawner.c */
void set_enemy_spawner_animations(Enemy_Spawner *ES, Texture_Manager *TM, Window *window, int index_enemy);
void set_friend_spawner_animations(Friend_Spawner *FS, Texture_Manager *TM, Window *window, int index_friend);
Friend_Spawner init_FS(int index_friend, Texture_Manager *TM, Window *window);
Enemy_Spawner init_ES(int index_enemy, Texture_Manager *TM, Window *window);

/* game/initializers/init_TM.c */
void set_img_size(MLV_Image *img, int width, int height);
Texture_Manager init_TM(Window window);
void free_TM(Texture_Manager *this);

/* game/game.c */
void quit_game(Texture_Manager *TM, Sound_Manager *SM);
void launch_newgame(btn_value gamemode, btn_value difficulty, char *p1_name, char *p2_name, Sound_Manager *SM);
void launch_resume(Game_Manager *GM, Sound_Manager *SM);

/* GUI/input.c */
void draw_input(Input *this);
Input get_new_input(Geometry g, char *placeholder, MLV_Color color, char *font_path);
void free_input(Input *this);
void set_hidden_input(Input *this);
void unset_hidden_input(Input *this);
void set_input_geometry(Input *this, int posX, int width);
bool exist_input(Input *this);

/* GUI/label.c */
void draw_label(Label *this);
Label get_new_label(Geometry g, char *text, MLV_Color color, char *font_path);
void set_hidden_lbl(Label *this);
void unset_hidden_lbl(Label *this);
void set_label_geometry(Label *this, int posX);

/* GUI/button.c */
void draw_button(Button *this);
bool is_btn_hover(Button *this, int posX, int posY);
bool is_btn_select(Button *this);
Button get_new_button(Geometry g, char *text, MLV_Color color, MLV_Color background_color, char *font_path, btn_value value);
void set_hover_btn(Button *this);
void unset_hover_btn(Button *this);
void set_select_btn(Button *this);
void unset_select_btn(Button *this);
void set_hidden_btn(Button *this);
void unset_hidden_btn(Button *this);

/* GUI/general.c */
void draw_input_or_label(Input *input, Label *label);
char *get_input_or_label_value(Input *input, Label *label);
void set_object_dimension(char *text, char *font_path, int font_size, int *object_width, int *object_height);
int get_object_font_size(char *text, char *font_path, int max_width, int max_height);

/* save/save.c */
void set_GMG(GM_list_games GMG);
void write_GMG(GM_list_games GMG);
void set_GMS(GM_list_scores GMS);
void write_GMS(GM_list_scores GMS);
void remove_saved_game(int id_game);
int get_unique_id();
void save_score(Game_Manager *GM, int time);
void save_game(Game_Manager *GM, int time);

