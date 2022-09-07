#include <stdio.h>
#include "battleship.h"
#include "ship_locations.h"
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    int** board;
    int ship_count = 4;
    int numOfRow = 7;
    int numOfCol = 7;
    int choice = -1;
    int i, a;
    char** table;
        

    FILE* ships;
    char* filename;
    char singleline[150];
    
    

    /*Set ships and map - Generating 2D array*/
    board = createBoard(&numOfRow, &numOfCol);
    table = shipsBoard(&ship_count, &numOfRow, &numOfCol); 
   
    
    /* Read the file and extract ship location into the table(shipsBoard)*/
       

    /* Check the command syntax*/
    if (argc < 2)
    {
        printf("Missing Filename\n");
        return 1;
    }
    else
    {
        filename = argv[1];
        printf("Get ships location from %s\n", filename);
    }

    /* Open file */
    ships = fopen(filename,"r");
    
    a = 0;
    /* File is opened successfully */
    if (ships)
    {
        while (fgets(singleline,150,ships) != NULL)
        {
            
                strcpy(table[a], singleline);
                
                a += 1;
        }
        
        /*printf("%s", table[1]);
        fflush(stdout); 
        sleep(3);
        fclose(ships);*/
    }
    else 
    {
        printf("Failed to open the file\n");
    }

   
     /*Update board*/
    getCoordinates(table, board, ship_count, &numOfCol, &numOfRow); 




    do {

    /*Automatically clear screen!*/
    system("clear");
                    
    /* Print menu */
    welcome();
       
    /*Update board*/
    getCoordinates(table, board, ship_count, &numOfCol, &numOfRow); 

    if (choice == 1)
    {         
        printGameBoard(board, &numOfRow, &numOfCol);
   
    }

  
    /* Run the option and peform tasks */
    printf("\n");
    printf("Wanna exact ship locations?? \n");
    printf("1. Show\n");
    printf("2. Exit\n");

    scanf("%d", &choice);


        }while (choice != 2);

    if (choice == 2){
           
        printf("~~~ I HOPE YOU HAVE FUN <3~~~\n");
    }

/*Free memory*/
    for (i = 0; i < numOfRow; i++)
    {
        free(board[i]);
    }
    free(board);

    for (i = 0; i < ship_count; i++)
    {
        free(table[i]);
    }
    free(table);

    return 0;
 }

 
