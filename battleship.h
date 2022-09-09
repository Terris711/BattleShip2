#include "linkedList.h"
void welcome();
int** createBoard(int* numOfRow, int* numOfCol);
void printGameBoard(int** board, int* numOfRow, int* numOfCol);
void getCoordinates(char** table, int** board, int ship_count, int* numOfRow, int* numOfCol);
void shoot(char** table,int** board, int x, int y);
int checkSunk(char** table, int** board, int ship_count, int* ShipStatus);
int checkWin(int* ShipStatus, int ship_count, int* win);
void saveBoard(LinkedList* list, int** board, int* numOfCol, int* numOfRow);





