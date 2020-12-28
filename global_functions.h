/* game/game.c */
void launch_newgame(btn_value gamemode, btn_value difficulty, char *p1_name, char *p2_name);
void launch_resume(Game_Manager *GM);

/* menu/controllers/mainPageC.c */
void launch_main_page(int width, int height);

/* save/save.c */
void set_GMG(GM_list_games GMG);
void write_GMG(GM_list_games GMG);
void set_GMS(GM_list_scores GMS);
void write_GMS(GM_list_scores GMS);
void remove_saved_game(int id_game);
int get_unique_id();
void save_score(Game_Manager *GM, int time);
void save_game(Game_Manager *GM, int time);

