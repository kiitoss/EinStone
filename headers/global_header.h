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

#include "headers/GUI.h"
#include "headers/game.h"
#include "headers/menu.h"

#include "headers/functions.h"

#endif
