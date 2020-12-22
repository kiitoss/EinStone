CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3

all: output clean

output: mainPageC.o menuC.o newGamePageC.o resumePageC.o scorePageC.o buttonM.o generalM.o inputM.o labelM.o mainPageM.o newgamePageM.o objectV.o pageV.o 
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` mainPageC.o menuC.o newGamePageC.o resumePageC.o scorePageC.o buttonM.o generalM.o inputM.o labelM.o mainPageM.o newgamePageM.o objectV.o pageV.o `pkg-config --libs-only-l MLV` -o output

mainPageC.o: ./controllers/mainPageC.c
	$(CC) $(CFLAGS) ./controllers/mainPageC.c -c -I ./

menuC.o: ./controllers/menuC.c
	$(CC) $(CFLAGS) ./controllers/menuC.c -c -I ./

newGamePageC.o: ./controllers/newGamePageC.c
	$(CC) $(CFLAGS) ./controllers/newGamePageC.c -c -I ./

resumePageC.o: ./controllers/resumePageC.c
	$(CC) $(CFLAGS) ./controllers/resumePageC.c -c -I ./

scorePageC.o: ./controllers/scorePageC.c
	$(CC) $(CFLAGS) ./controllers/scorePageC.c -c -I ./

buttonM.o: ./models/objects/buttonM.c
	$(CC) $(CFLAGS) ./models/objects/buttonM.c -c -I ./

generalM.o: ./models/objects/generalM.c
	$(CC) $(CFLAGS) ./models/objects/generalM.c -c -I ./

inputM.o: ./models/objects/inputM.c
	$(CC) $(CFLAGS) ./models/objects/inputM.c -c -I ./

labelM.o: ./models/objects/labelM.c
	$(CC) $(CFLAGS) ./models/objects/labelM.c -c -I ./

mainPageM.o: ./models/pages/mainPageM.c
	$(CC) $(CFLAGS) ./models/pages/mainPageM.c -c -I ./

newgamePageM.o: ./models/pages/newgamePageM.c
	$(CC) $(CFLAGS) ./models/pages/newgamePageM.c -c -I ./

objectV.o: ./views/objectV.c
	$(CC) $(CFLAGS) ./views/objectV.c -c -I ./

pageV.o: ./views/pageV.c
	$(CC) $(CFLAGS) ./views/pageV.c -c -I ./

clean:
	rm -rf *.o
