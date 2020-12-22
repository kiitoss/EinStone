/*
------------------------------------------------------------

MAKMAK from path: ./

------------------------------------------------------------
*/
/* models/animationM.c */
MLV_Animation *get_animation(MLV_Image *sprite, int rectsize, int row_animation, int first_frame, int last_frame, int time);

/* models/friendSpawnerM.c */
Friend_Spawner init_FS(int index_friend, Texture_Manager *TM, Window *window);

/* models/gameManagerM.c */
Game_Manager init_GM(Window *window, Texture_Manager *TM);

/* models/textureManagerM.c */
Texture_Manager init_TM(Window window);

/* models/windowM.c */
Window init_window(unsigned int win_width, unsigned int win_height);

