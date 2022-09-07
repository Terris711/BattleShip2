#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[])
{
    FILE* ships;
    char* filename;
    char singleline[150];
    

    /* Check the command syntax*/
    if (argc < 2)
    {
        printf("Missing Filename\n");
        return 1;
    }
    else
    {
        filename = argv[1];
        printf("Get ships location from: %s\n", filename);
    }

    /* Open file */
    ships = fopen(filename,"r");

    /* File is opened successfully */
    if (ships)
    {
        printf("Ship locations:\n");
        printf("\n");
        while (!feof(ships))
        {
            fgets(singleline, 150, ships);
            puts(singleline);
        }
        printf("\n"); 
        fclose(ships);
    }
    else 
    {
        printf("Failed to open the file\n");
    }

    /* Get access to file element */

    
    return 0;

}
