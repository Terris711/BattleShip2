#include <stdio.h>
#include "battleship.h"
#include "ship_locations.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "linkedList.h"


int main(int argc, char* argv[])
{
    FILE* ships;
    char* filename;
    char singleline[150];

    int ShipStatus[4];
    int** board;
    int ship_count = 4;
    int numOfRow = 7;
    int numOfCol = 7;
    int choice = -1;
    char** table;
    int x,y,i, a, s;
    char tempRow;
    int win;
    LinkedList* list = NULL;
    


    printListFunc* printList = printElement;
    win = 0; /* False */



    /*Set ships and map - Generating 2D array*/
    board = createBoard(&numOfRow, &numOfCol);
    table = shipsBoard(&ship_count, &numOfRow, &numOfCol); 
     
    /* Initialize ship status as 0 - not being sunk */
    for ( s = 0; s < 4; s++)
    {
        ShipStatus[s] = 0;
    }
    
    printf("%d", ShipStatus[0]);




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
        sleep(3);*/
        fclose(ships);
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
            
            /*shoot(table, board, 0,1);
            shoot(table, board, 0,2);
            shoot(table, board, 0,3);

            shoot(table, board, 3,4);
            shoot(table, board, 2,4);
            shoot(table, board, 1,4);

            shoot(table, board, 2,2);
            shoot(table, board, 3,2);

            shoot(table, board, 5,6);
            shoot(table, board, 4,6);
            shoot(table, board, 3,6);
            shoot(table, board, 2,6);
            shoot(table, board, 1,6);

            printGameBoard(board, &numOfRow, &numOfCol);*/
            
            printf("\n");
            checkSunk(table, board, ship_count, ShipStatus);
            printf("\n");
            
            win = checkWin(ShipStatus, ship_count, &win);
            if (win == 1)
            {
                printf("\n");
                printf("You win!");
                printf("\n");
            }
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
        printf("Saving your progress .....");
        saveBoard(list, board, &numOfRow, &numOfCol);
        printLinkedList(list, &printList);
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

 
