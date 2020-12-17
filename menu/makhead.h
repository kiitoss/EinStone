/*
------------------------------------------------------------

MAKMAK from path: ./

------------------------------------------------------------
*/
/* controllers/mainPageC.c */
void launch_main_page(int width, int height);

/* models/objects/buttonM.c */
Button get_new_button(Geometry g, char *text, MLV_Color color, char *font_path, menu_choice value);

/* models/objects/generalM.c */
void set_object_dimension(char *text, char *font_path, int font_size, int *object_width, int *object_height);
int get_object_font_size(char *text, char *font_path, int max_width, int max_height);

