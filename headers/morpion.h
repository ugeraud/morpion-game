#ifndef MORPION_H
#define MORPION_H

#define LENGTH_PIECE 2
#define LENGTH_NAME 10
#define LENGTH 3
#define ZERO 0

void bookPlace2x2(char * tab[], int length);
/**void bookPlace1x1(char * tab);**/
void freePlace2x2(char * tab[], int length);
void freePlace1x1(char * tab);
void initBoard(char * tab[], int length);
void printBoard(char * tab[],int length);
void config(char * name[],char gamePiece[LENGTH_PIECE]);
int playCase(char * tab[], char c,char name[LENGTH_NAME]);
int winner(char * tab[],  int length);
void printGameOverMessage(char name[LENGTH_NAME]);
void printMessageWhenNoWinner(char * tab[]);
void printMessageWhenNoCaseAvailable(char * tab[]);
#endif // MORPION_H
