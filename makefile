CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3

all: output clean

output: mainC.o animationM.o friendSpawnerM.o gameManagerM.o textureManagerM.o windowM.o mainPageC.o menuC.o newGamePageC.o resumePageC.o scorePageC.o buttonM.o generalM.o inputM.o labelM.o mainPageM.o newgamePageM.o resumePageM.o objectV.o pageV.o 
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` mainC.o animationM.o friendSpawnerM.o gameManagerM.o textureManagerM.o windowM.o mainPageC.o menuC.o newGamePageC.o resumePageC.o scorePageC.o buttonM.o generalM.o inputM.o labelM.o mainPageM.o newgamePageM.o resumePageM.o objectV.o pageV.o `pkg-config --libs-only-l MLV` -o output

mainC.o: ./game/controllers/mainC.c
	$(CC) $(CFLAGS) ./game/controllers/mainC.c -c -I ./

animationM.o: ./game/models/animationM.c
	$(CC) $(CFLAGS) ./game/models/animationM.c -c -I ./

friendSpawnerM.o: ./game/models/friendSpawnerM.c
	$(CC) $(CFLAGS) ./game/models/friendSpawnerM.c -c -I ./

gameManagerM.o: ./game/models/gameManagerM.c
	$(CC) $(CFLAGS) ./game/models/gameManagerM.c -c -I ./

textureManagerM.o: ./game/models/textureManagerM.c
	$(CC) $(CFLAGS) ./game/models/textureManagerM.c -c -I ./

windowM.o: ./game/models/windowM.c
	$(CC) $(CFLAGS) ./game/models/windowM.c -c -I ./

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
