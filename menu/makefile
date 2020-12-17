CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3

all: output clean

output: mainPageC.o buttonM.o generalM.o 
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` mainPageC.o buttonM.o generalM.o `pkg-config --libs-only-l MLV` -o output

mainPageC.o: ./controllers/mainPageC.c
	$(CC) $(CFLAGS) ./controllers/mainPageC.c -c -I ./

buttonM.o: ./models/objects/buttonM.c
	$(CC) $(CFLAGS) ./models/objects/buttonM.c -c -I ./

generalM.o: ./models/objects/generalM.c
	$(CC) $(CFLAGS) ./models/objects/generalM.c -c -I ./

clean:
	rm -rf *.o
