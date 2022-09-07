#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"
#include "fileIO.h"  

char* readFile( char* filename, int* ship_count, int* numOfRow, int* numOfCol)
{
    /* File pointer to content file*/
    FILE* shipLocation;

    /* Error check: show errors or return NULL if there is no error */
    char* error;

    /* the value is being set of ship_count, numOfRow and numOfCol*/
    char value;

    /* Temporary variable to store ship value*/
    int tempVal;

    /* Error- checking in fscanf() */
    int ReadErr;

    /* Control flag */
    int reading;
    reading = 1;


    shipLocation = fopen( filename, "r");

    error = (char*)malloc(128 * sizeof(char));
    *error = '\0'; /* set error as NULL initially when the program does have error */

    *ship_count = 0;
    *numOfRow = 0;
    *numOfCol = 0;

    if (shipLocation == NULL)
    {
        /* File cannot open */
        strncpy(error, "File does not open! ", 25);
        
        /* Add message to error string*/
        strncat(error, strerror(errno), 50);
    }
    else if (ferror(shipLocation))
    {
        /* Open file but have problem */
        strncpy (error, "Can not read the file! ", 25);
        strncat(error, strerror(errno), 50);
        fclose(shipLocation); 

    }
    else
    {
        /* Open file successfully*/
        while (reading)
        {
            ReadErr = fscanf( shipLocation, "%c = %d\n", &value, &tempVal);

            if (ReadErr != 2)
            {
                strncpy(error, "File syntax is incorrect", 35);
                reading = 0;
            }
            else if( tempVal <= 0)
            {
                /*Value out of bounds*/
                sprintf(error, "File syntax is incorrect! %c settings is out of bound", value);
                reading = 0;
            }
            else if( value == 'ship_count')
            {
                if(*ship_count != 0)
                {
                    /* ship_count is already set */
                    strncpy(error, "File syntax is incorrect! Ship_count is already set", 50);
                    reading = 0;
                }
                else
                {
                    *ship_count = tempVal;
                }
            }
            else if( value == "numOfCol")
            {
                if(*ship_count != 0)
                {
                    /* ship_count is already set */
                    strncpy(error, "File syntax is incorrect! numOfCol is already set", 50);
                    reading = 0;
                }
                else
                {
                    *numOfCol = tempVal;
                }
             }
            else if( value == "numOfRow")
            {
                if(*numOfRow != 0)
                {
                    /* ship_count is already set */
                    strncpy(error, "File syntax is incorrect! numOfRow is already set", 50);
                    reading = 0;
                }
                else
                {
                    *numOfRow = tempVal;
                }
             }

             if (reading)
             {
                /* Keep reading untill it reaches the end of the file*/
                reading = !feof(shipLocation);
             }
            
        }

        fclose(shipLocation);

        if (*ship_count == 0 || *numOfCol == 0 || *numOfRow == 0)
        {
            strncpy(error, "Assigning unsuccessfully", 45);
        }
        else if(*error == '\0')
        {
            /*No error*/
            free(error);
            error = NULL;
        }

    }

    return error;

}
