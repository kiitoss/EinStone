/*
------------------------------------------------------------

MAKMAK from path: ./

------------------------------------------------------------
*/
/* controllers/mainPageC.c */
void launch_main_page(int width, int height);

/* controllers/newGamePageC.c */
void launch_newgame_page(int width, int height);

/* models/objects/buttonM.c */
bool is_btn_hover(Button *this, int posX, int posY);
bool is_btn_select(Button *this);
Button get_new_button(Geometry g, char *text, MLV_Color color, char *font_path, menu_choice value);
void set_hover_btn(Button *this);
void unset_hover_btn(Button *this);
void set_select_btn(Button *this);
void unset_select_btn(Button *this);
void set_hidden_btn(Button *this);
void unset_hidden_btn(Button *this);

/* models/objects/generalM.c */
void set_object_dimension(char *text, char *font_path, int font_size, int *object_width, int *object_height);
int get_object_font_size(char *text, char *font_path, int max_width, int max_height);

/* models/objects/inputM.c */
Input get_new_input(Geometry g, char *placeholder, MLV_Color color, char *font_path);
void free_input(Input *this);
void set_hidden_input(Input *this);
void unset_hidden_input(Input *this);
void set_input_geometry(Input *this, int posX, int width);
bool exist_input(Input *this);

/* models/objects/labelM.c */
Label get_new_label(Geometry g, char *text, MLV_Color color, char *font_path);
void set_hidden_lbl(Label *this);
void unset_hidden_lbl(Label *this);
void set_label_geometry(Label *this, int posX);

/* models/pages/mainPageM.c */
mainPage init_main_page(int width, int height);
Button *get_main_page_hover_btn(mainPage *this, int posX, int posY);

/* models/pages/newgamePageM.c */
void set_player_name(newgamePage *this, MLV_Input_box *input_box, char *text_input);
void set_difficulty(newgamePage *this, menu_choice btn_value);
void set_gamemode(newgamePage *this, menu_choice btn_value);
newgamePage init_newgame_page(int width, int height);
Button *get_newgame_page_hover_btn(newgamePage *this, int posX, int posY);

/* views/objectV.c */
void draw_button(Button *this);
void draw_label(Label *this);
void draw_input(Input *this);
void draw_input_or_label(Input *input, Label *label);

/* views/pageV.c */
Event_Manager get_event();
void draw_main_page(mainPage *mp);
void draw_newgame_page(newgamePage *ngp);

