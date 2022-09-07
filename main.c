#include <stdio.h>
#include "battleship.h"
#include "ship_locations.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
    int** board;
    int ship_count = 4;
    int numOfRow = 7;
    int numOfCol = 7;
    int choice = -1;
    char** table;
    int x, y, i, a;
    char tempRow;
    int numOfShipSunk;
    numOfShipSunk = 0;
    int win;
    win = 0; /* False */


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
    

    /* Print gameboard */
    printGameBoard(board, &numOfRow, &numOfCol);

    
        
    if (choice == 1)
    {         
        /*Shoot*/
    
        printf("\n"); 
        printf("Enter row (A/B/C/D/E ...): ");
        scanf(" %c", &tempRow);
        x =  tempRow - 'A';

        printf("Enter column (1/2/3/4/5 ...): ");
        scanf(" %d", &y);
          
        if ( x >= 0 && x < numOfCol && y >= 0 && y < numOfRow)
        { 
                       
            /*Automatically clear screen!*/
            system("clear");
            printf("\n");       
            shoot(table, board, x,y); 
            printf("\n");
            printGameBoard(board, &numOfRow, &numOfCol);

            checkSunk(table, board, ship_count, &numOfShipSunk);
            printf("%d", numOfShipSunk);
            
            /*
            win = checkWin(*numOfShipSunk, ship_count, *win)
            if (win == 1)
            {
                printf("You win!")
            }
            */
        }
        else
        {
            printf("\n");
            printf("Please enter valid coordinates!!!");
            printf("\n");
        }
    }

    else if(choice == 2)
    {
        printf("Save");
    }

    else if(choice == 3)
    {
        printf("Load");
    }

    else if(choice == 4)
    {
        printf("Replay");
    }

    else
    {
        printf("\n");
        printf("The game does not have this feature!!!");
        printf("\n");
    }


       /* Run the option and peform tasks */
    printf("\n");
    printf("Enter a command: \n");
    printf("1. Shoot\n");
    printf("2. Save\n");
    printf("3. Load\n");
    printf("4. Replay\n");
    printf("5. Exit\n");

    scanf("%d", &choice);
 

        }while (choice != 5);

    if (choice == 5){
           
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

 
