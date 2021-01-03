#ifndef   GLOBAL_H
#define   GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <time.h>

enum bool {false, true};
typedef enum bool bool;

#define SAVED_GAMES 5
#define SAVED_SCORES 10
#define FULL_SCREEN true

#include "./GUI.h"
#include "./game.h"
#include "./menu.h"

#include "./functions.h"

#endif
