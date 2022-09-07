#include<stdlib.h>
#include<string.h>
#include"ship_locations.h"

/*  this file and the corresponding header file (ship_locations.c and ship_locations.h) contains a
    single function you can use to get some metadata that you need to create
    the 2d map array in your game. 
    
    if you want to make your own metadata for the map (e.g changing the ship positions),
    you can modify the metadata table here. keep in mind that
    we will test your assignment with our own metadata. */
char** shipsBoard(int* ship_count, int* numOfRow, int* numOfCol)
{
    int i;
    char** table;

    *ship_count = 4;        /* the number of enemy ships in the playable area */
    *numOfRow = 7;       /* the map row size you will create later */
    *numOfCol = 7;       /* the map column size you will create later */

    /* now it is time to malloc the array of strings */
    table = (char**) malloc(sizeof(char*) * (*ship_count));

    for(i = 0 ; i < (*ship_count) ; i++)
    {
        /*each string is also mallocc'd, don't forget to free them! */
        table[i] = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    }
    
    /* now it is time to fill the array of strings with the data */
    /*strcpy(table[0], "D4 N 3 Nullbyte Submarine");
    strcpy(table[1], "A1 S 3 SSASR Popoto");
    strcpy(table[2], "C2 E 2 CPN \"Rogers\" Steve");
    strcpy(table[3], "F6 W 5 BS Galactica");*/

    return table; /* return the array */

    /* remember, you need to free this 2d table at some point once you finish
       extracting its information to create your own 2d map array in
       the main function. */
}
