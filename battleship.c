#include <stdio.h>
#include <stdlib.h>
#include "battleship.h"
#include "ship_locations.h"
#include <string.h>

#define COLOUR_HIT() printf("\033[0;32m") /* Set color to GREEN when hit successfully*/
#define COLOUR_FAIL()  printf("\033[0;31m") /* Set color to RED when hit failed */
#define COLOUR_RESET() printf("\033[0m") /* Reset colour */


void welcome()
{
    /* Print the menu*/
    printf("************************************************************\n");
    printf("***************WELCOME TO MY BATTLE SHIP GAME!**************\n");
    printf("************************************************************\n");
    printf("\n"); 
    }


/* 2D array to display shoots and misses*/
int** createBoard(int* numOfRow, int* numOfCol)
{
    int i;
    int line, column;

    int** board = malloc(*numOfRow * sizeof(int*));
    for (i = 0; i < *numOfRow; i++)
    {
        board[i] = malloc(*numOfCol * sizeof(int));
    }
    
    /*Initial value of board*/ 
    for (line = 0; line < *numOfRow; line ++){
        for (column = 0; column < *numOfCol; column ++){
            board[line][column] = -1 ; /* set -1 as a initial default value for further display */ 
            }

    }

    return board;
}


void printGameBoard(int** board, int* numOfRow, int* numOfCol)
{
    int i, line, column;
    int colMark = 65;
    

    printf("   ");
    /*Print letter coordinates*/
    for (column = 0; column < *numOfCol; column ++)
    {
        printf("%c|", colMark);
        colMark = colMark + 1;
    }

    printf("\n");
    
    /*Print number coordinates*/
    for (line = 0; line < *numOfRow; line ++)
    {
        /*Adjust "-" */
        for ( i = 0; i < *numOfCol * 2.5; i++)
        {
            printf("-");
        }

        printf("\n");
        
        printf(" %d|", line);
        
        for (column = 0; column < *numOfCol; column ++)
        {
            if (board[column][line] == -1){
                printf(" |");
            }else if( board[column][line] == 1){
                COLOUR_HIT();
                printf("X|"); /* Shoot successfully!*/
                COLOUR_RESET();
            }else if ( board[column][line] == 0){
                COLOUR_FAIL();
                printf("O|"); /* Shoot failed!*/
                COLOUR_RESET();
            }else if (board[column][line] >= 10) /*Where the ship is placed*/
            {
                printf(" |"); /*Position of ships*/
                
            }

        } 
            printf("\n");
        }
}


/*The game starts with coordinates (0,0)*/

void getCoordinates(char** table, int** board, int ship_count, int* numOfRow, int* numOfCol)
{
    int i; /*row of table*/
    int j;
    int x,y,step; /*Ship coordinates (x,y)*/
    char dir;
    char tempX,tempY,tempStep;
    
    

    /* find x*/
    for (i = 0; i < ship_count; i++)
    {
        /*Get x - because x is a character so I have to convert it!*/
        tempX = table[i][0];
        x = tempX - 'A';
        
        /*Get y*/
        tempY = table[i][1];
        y = tempY - '0';
        
        /*Get direction of the ship*/
        dir = table[i][3];

        /*Get length of the ship*/
        tempStep = table[i][5];
        step = tempStep - '0';

        /*Update data from table to board*/  
        

        if (dir == 'N')
        {
            for (j = 0; j < step; j++)
            {        
                board[x][y - j] = 10 + i;
                }
            }
        else if (dir == 'S')
        {
             for (j = 0; j < step; j++)
             {        
                board[x][y + j] = 10 + i;
                }
            }
        else if(dir == 'E')
        {
             for (j = 0; j < step; j++)
             {        
                board[x + j][y] = 10 + i;
                }
            }
        else if (dir == 'W')
        {
             for (j = 0; j < step; j++)
             {        
                board[x - j][y] = 10 + i;
                }
            }


    }

      
}


void shoot(char** table, int** board, int x, int y)
{
     int i,j;
     
     /* Assign ship = 10, 11, 12, 13...*/
     if (board[x][y] >= 10)
     {       
                        
             i = board[x][y] - 10;
               
             printf("You shoot ship of captain: ");
          
             for (j = 7; j < strlen(table[i]); j++)
             {
                 printf("%c",table[i][j]);
             }
  
            
             board[x][y] = 1;
             printf("\n");    

     }
     else
     {
             board[x][y] = 0;
             printf("Miss!");
             printf("\n");
     }
}

/* Checking from the starting point of ship till the end length of the ship, if all board[column][line] = 1, the ship is sunk => then print out the sunk message*/
int checkSunk(char** table, int** board, int ship_count, int* numOfShipSunk)
{
    int i; /*row of table*/
    int j;
    int x,y,step; /*Ship coordinates (x,y)*/
    char dir;
    char tempX,tempY,tempStep;
    int numOfShoot;
    numOfShoot = 0;
    
    

    /* find x*/
    for (i = 0; i < ship_count; i++)
    {
        /*Get x*/
        tempX = table[i][0];
        x = tempX - 'A';
        
        /*Get y*/
        tempY = table[i][1];
        y = tempY - '0';
        
        /*Get direction of the ship*/
        dir = table[i][3];

        /*Get length of the ship*/
        tempStep = table[i][5];
        step = tempStep - '0';
        
        
        /* Find end looping point 
         * If number of shoot (right) equal to step( length of the ship) => the ship is sunk */
        if (dir == 'N')
        {
            for (j = 0; j < step; j++)
            {        
                if (board[x][y - j] == 1)
                {
                    numOfShoot += 1;   
                }
                
            }
                if (numOfShoot == step)
                {
                    *numOfShipSunk += 1;
                
                }
                
            
        }


        else if (dir == 'S')
        {
             for (j = 0; j < step; j++)
             {        
                if (board[x][y + j] == 1)
                {
                    numOfShoot += 1;   
                }
                
            }
                if (numOfShoot == step)
                {
                    *numOfShipSunk += 1;
                }
                
        }


        else if(dir == 'E')
        {
             for (j = 0; j < step; j++)
             {        
                if (board[x + j][y] == 1)
                {
                    numOfShoot += 1;   
                }
                
            }
                if (numOfShoot == step)
                {
                    *numOfShipSunk += 1;
                }
                
        }


        else if (dir == 'W')
        {
             for (j = 0; j < step; j++)
             {        
                if (board[x - j][y] == 1)
                {
                    numOfShoot += 1;   
                }
                
             }
                if (numOfShoot == step)
                {
                    *numOfShipSunk += 1;
                }
                
        }
    }


    return 0;
}

/* if the number of ship sunk = ship_count ==> win the game*/
/*int checkWin(int* numOfShipSunk, int ship_count, int* win)
{
    if (*numOfShipSunk == ship_count)
    {
        win = 1; 
    }

    return win;
}
*/
