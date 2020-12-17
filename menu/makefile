CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3

all: output clean

output: mainPageC.o buttonM.o generalM.o mainPageM.o objectV.o pageV.o 
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` mainPageC.o buttonM.o generalM.o mainPageM.o objectV.o pageV.o `pkg-config --libs-only-l MLV` -o output

mainPageC.o: ./controllers/mainPageC.c
	$(CC) $(CFLAGS) ./controllers/mainPageC.c -c -I ./

buttonM.o: ./models/objects/buttonM.c
	$(CC) $(CFLAGS) ./models/objects/buttonM.c -c -I ./

generalM.o: ./models/objects/generalM.c
	$(CC) $(CFLAGS) ./models/objects/generalM.c -c -I ./

mainPageM.o: ./models/pages/mainPageM.c
	$(CC) $(CFLAGS) ./models/pages/mainPageM.c -c -I ./

objectV.o: ./views/objectV.c
	$(CC) $(CFLAGS) ./views/objectV.c -c -I ./

pageV.o: ./views/pageV.c
	$(CC) $(CFLAGS) ./views/pageV.c -c -I ./

clean:
	rm -rf *.o
