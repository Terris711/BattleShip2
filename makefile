
CC=gcc
OBJ=main.o battleship.o ship_locations.o 
CFLAGS= -Wall -ansi -g -pedantic
EXEC=videoGame



$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) 


main.o: main.c battleship.h ship_locations.h
	$(CC) $(CFLAGS) -c main.c

battleship.o: battleship.c battleship.h ship_locations.h 
	$(CC) $(CFLAGS) -c battleship.c -D DEBUG=1

ship_location.o: ship_locations.c ship_locations.h
	$(CC) $(CFLAGS) -c ship_locations.c

clean:
	rm -i $(EXEC) $(OBJ)





CC=gcc
OBJ2=main1.o battleshipD.o ship_locations.o 
CFLAGS= -Wall -ansi -g -pedantic
SHOW=videoGame-debug

$(SHOW): $(OBJ2)
	$(CC) $(OBJ2) -o $(SHOW) 


main1.o: main1.c battleship.h ship_locations.h
	$(CC) $(CFLAGS) -c main1.c

battleshipD.o: battleshipD.c battleship.h ship_locations.h 
	$(CC) $(CFLAGS) -c battleshipD.c -D DEBUG=1




