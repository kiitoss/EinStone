/*
------------------------------------------------------------

MAKMAK from path: ./

------------------------------------------------------------
*/
/* controllers/mainPageC.c */
void launch_main_page(int width, int height);

/* models/objects/buttonM.c */
bool is_btn_hover(Button *this, int posX, int posY);
Button get_new_button(Geometry g, char *text, MLV_Color color, char *font_path, menu_choice value);
void set_hover_btn(Button *this);
void unset_hover_btn(Button *this);

/* models/objects/generalM.c */
void set_object_dimension(char *text, char *font_path, int font_size, int *object_width, int *object_height);
int get_object_font_size(char *text, char *font_path, int max_width, int max_height);

/* models/pages/mainPageM.c */
mainPage init_main_page(int width, int height);
Button *get_main_page_hover_btn(mainPage *this, int posX, int posY);

/* views/objectV.c */
void draw_button(Button *this);

/* views/pageV.c */
Event_Manager get_event();
void draw_main_page(mainPage *mp);

