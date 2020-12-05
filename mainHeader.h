#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>


enum bool {false, true};
typedef enum bool bool;

typedef struct {
  MLV_Keyboard_button key_pressed;
  int mouseX;
  int mouseY;
  MLV_Button_state button_state;
} Event_Manager;
