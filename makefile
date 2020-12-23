CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3

all: output clean

output: enemyC.o friendC.o mainC.o playerC.o rowC.o animationM.o enemyM.o friendM.o gameManagerM.o playerM.o rowM.o spawnerM.o textureManagerM.o windowM.o gameV.o windowV.o mainPageC.o menuC.o newGamePageC.o resumePageC.o scorePageC.o buttonM.o generalM.o inputM.o labelM.o mainPageM.o newgamePageM.o resumePageM.o objectV.o pageV.o 
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` enemyC.o friendC.o mainC.o playerC.o rowC.o animationM.o enemyM.o friendM.o gameManagerM.o playerM.o rowM.o spawnerM.o textureManagerM.o windowM.o gameV.o windowV.o mainPageC.o menuC.o newGamePageC.o resumePageC.o scorePageC.o buttonM.o generalM.o inputM.o labelM.o mainPageM.o newgamePageM.o resumePageM.o objectV.o pageV.o `pkg-config --libs-only-l MLV` -o output

enemyC.o: ./game/controllers/enemyC.c
	$(CC) $(CFLAGS) ./game/controllers/enemyC.c -c -I ./

friendC.o: ./game/controllers/friendC.c
	$(CC) $(CFLAGS) ./game/controllers/friendC.c -c -I ./

mainC.o: ./game/controllers/mainC.c
	$(CC) $(CFLAGS) ./game/controllers/mainC.c -c -I ./

playerC.o: ./game/controllers/playerC.c
	$(CC) $(CFLAGS) ./game/controllers/playerC.c -c -I ./

rowC.o: ./game/controllers/rowC.c
	$(CC) $(CFLAGS) ./game/controllers/rowC.c -c -I ./

animationM.o: ./game/models/animationM.c
	$(CC) $(CFLAGS) ./game/models/animationM.c -c -I ./

enemyM.o: ./game/models/enemyM.c
	$(CC) $(CFLAGS) ./game/models/enemyM.c -c -I ./

friendM.o: ./game/models/friendM.c
	$(CC) $(CFLAGS) ./game/models/friendM.c -c -I ./

gameManagerM.o: ./game/models/gameManagerM.c
	$(CC) $(CFLAGS) ./game/models/gameManagerM.c -c -I ./

playerM.o: ./game/models/playerM.c
	$(CC) $(CFLAGS) ./game/models/playerM.c -c -I ./

rowM.o: ./game/models/rowM.c
	$(CC) $(CFLAGS) ./game/models/rowM.c -c -I ./

spawnerM.o: ./game/models/spawnerM.c
	$(CC) $(CFLAGS) ./game/models/spawnerM.c -c -I ./

textureManagerM.o: ./game/models/textureManagerM.c
	$(CC) $(CFLAGS) ./game/models/textureManagerM.c -c -I ./

windowM.o: ./game/models/windowM.c
	$(CC) $(CFLAGS) ./game/models/windowM.c -c -I ./

gameV.o: ./game/views/gameV.c
	$(CC) $(CFLAGS) ./game/views/gameV.c -c -I ./

windowV.o: ./game/views/windowV.c
	$(CC) $(CFLAGS) ./game/views/windowV.c -c -I ./

mainPageC.o: ./menu/controllers/mainPageC.c
	$(CC) $(CFLAGS) ./menu/controllers/mainPageC.c -c -I ./

menuC.o: ./menu/controllers/menuC.c
	$(CC) $(CFLAGS) ./menu/controllers/menuC.c -c -I ./

newGamePageC.o: ./menu/controllers/newGamePageC.c
	$(CC) $(CFLAGS) ./menu/controllers/newGamePageC.c -c -I ./

resumePageC.o: ./menu/controllers/resumePageC.c
	$(CC) $(CFLAGS) ./menu/controllers/resumePageC.c -c -I ./

scorePageC.o: ./menu/controllers/scorePageC.c
	$(CC) $(CFLAGS) ./menu/controllers/scorePageC.c -c -I ./

buttonM.o: ./menu/models/objects/buttonM.c
	$(CC) $(CFLAGS) ./menu/models/objects/buttonM.c -c -I ./

generalM.o: ./menu/models/objects/generalM.c
	$(CC) $(CFLAGS) ./menu/models/objects/generalM.c -c -I ./

inputM.o: ./menu/models/objects/inputM.c
	$(CC) $(CFLAGS) ./menu/models/objects/inputM.c -c -I ./

labelM.o: ./menu/models/objects/labelM.c
	$(CC) $(CFLAGS) ./menu/models/objects/labelM.c -c -I ./

mainPageM.o: ./menu/models/pages/mainPageM.c
	$(CC) $(CFLAGS) ./menu/models/pages/mainPageM.c -c -I ./

newgamePageM.o: ./menu/models/pages/newgamePageM.c
	$(CC) $(CFLAGS) ./menu/models/pages/newgamePageM.c -c -I ./

resumePageM.o: ./menu/models/pages/resumePageM.c
	$(CC) $(CFLAGS) ./menu/models/pages/resumePageM.c -c -I ./

objectV.o: ./menu/views/objectV.c
	$(CC) $(CFLAGS) ./menu/views/objectV.c -c -I ./

pageV.o: ./menu/views/pageV.c
	$(CC) $(CFLAGS) ./menu/views/pageV.c -c -I ./

clean:
	rm -rf *.o
