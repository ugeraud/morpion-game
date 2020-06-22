#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/morpion.h"

int i,j;

/** Book Place 2x2 tab**/
void bookPlace2x2(char * tab[], int length)
{
	i=0;
	for (i = 0; i < length; i++)
		tab[i]= (char *) malloc(sizeof(char));	
}

/** Book Place 1x1 tab
void bookPlace1x1(char * tab)
{
	tab= (char *) malloc(sizeof(char));	
}
**/

/** Free Place booked 2x2 tab**/
void freePlace2x2(char * tab[], int length)
{
	i=0;
	for (i = 0; i < length; i++)
		free(tab[i]);	
}

/** Free Place booked 1x1 tab**/
void freePlace1x1(char * tab)
{
	free(tab);	
}

/** Init Board **/
void initBoard(char * tab[],int length)
{
    i=0;
    j=0;
	
    for (i = 0; i < length; i++) 
	{
        for (j = 0; j < length; j++) 
			tab[i][j] = '-';
    }
}

/** Print Board **/
void printBoard(char * tab[],int length)
{
    i=0;
    j=0;
	printf("\033[1;31m");
	printf("\n");
	printf("\t\t\t  0 1 2 \n");
    for (i = 0; i < length; i++) 
	{
        for (j = 0;	j < length;	j++)
		{
			if (j==0) 
			{
				printf("\t\t\t");
				printf("%d ",i);
			}
			printf("%c ", tab[i][j]);
		}
		
		printf("\n");
    }
	printf("\n");
	printf("\033[0m");
}

/** Config player's name **/
void config(char * name[], char gamePiece[LENGTH_PIECE])
{
	char line[LENGTH_NAME];
	char temp[ZERO];
	char c;

	printf("Welcome in the game, let do the configuration....\n\n");
	printf("Player 1: What's your name ? ");
	scanf("%s",line);
	while ((getchar()) != '\n'); 
	if (line[0] >= 'a' && line[0] <= 'z')
	{
		temp[0] = line[0] - 32;	
		strncpy(line,temp,1);
	}
	
	strcpy(name[0], line);
	strcpy(line," ");

	do {
		printf("\nWelcome \033[0;34m %s \033[0m, please choose your piece game (X or O): ",name[0]);
		scanf("%c",&c);
		while ((getchar()) != '\n'); 
		
		if (c >= 'a' && c <= 'z')
		{
			c = c - 32;
			if(c == 'X' || c == 'O')
				gamePiece[0] = c;
		}	
		else if(c >= 'A' && c <= 'Z')
		{
			if(c == 'X' || c == 'O')
				gamePiece[0] = c;
		}
			
	} while (gamePiece[0] != 'X' && gamePiece[0] != 'O');

	printf("\nThanks \033[0;34m %s \033[0m ! Let configure the player 2.", name[0]);
	printf("\n\nPlayer 2: What's your name ? ");
	scanf("%s",line);
	while ((getchar()) != '\n'); 
	
	if (line[0] >= 'a' && line[0] <= 'z')
	{
		temp[0] = line[0] - 32;	
		strncpy(line,temp,1);
	}

	strcpy(name[1], line);
	strcpy(line," ");

	if (gamePiece[0] == 'X') gamePiece[1] = 'O';
	else gamePiece[1] = 'X';
	
	printf("\nWelcome \033[0;32m %s \033[0m, your piece game is \033[1;33m'%c'\033[0m.\n\n",name[1], gamePiece[1]);
	printf("Good job, let start now ...\n\n");
}

/** Play Case **/
int playCase(char * tab[], char c, char name[LENGTH_NAME])
{
	int x, y;
	x=0;
	y=0;
	printf("Play one case %s..\n", name);
    printf("Play <x> position : ");
    scanf("%d", &x);
    printf("Play <y> position : ");
    scanf("%d",&y);

	if(x< 3 && y < 3)
	{
		if(tab[x][y] == '-')
		{
			tab[x][y] = c;
			return 1;
		}
	}
	
	return 0;
}

/** Check if someone win **/
int winner(char * tab[], int length)
{
	i=0;
    j=0;
	short int compteur;
    

	if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2] && tab[0][0] != '-') return 1;
	else if (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0] && tab[0][2] != '-') return 1;
	else if (tab[0][0] == tab[0][1] && tab[0][1] == tab[0][2] && tab[0][0] != '-') return 1;
	else if (tab[1][0] == tab[1][1] && tab[1][1] == tab[1][2] && tab[1][0] != '-') return 1;
	else if (tab[2][0] == tab[2][1] && tab[2][1] == tab[2][2] && tab[2][0] != '-') return 1;
	else if (tab[0][0] == tab[1][0] && tab[1][0] == tab[2][0] && tab[0][0] != '-') return 1;
	else if (tab[0][1] == tab[1][1] && tab[1][1] == tab[2][1] && tab[0][1] != '-') return 1;
	else if (tab[0][2] == tab[1][2] && tab[1][2] == tab[2][2] && tab[0][2] != '-') return 1;
	else
	{
		compteur=0;
		for (i = 0; i < length; i++) 
		{
			for (j = 0; j < length; j++) 
			{
				if(tab[i][j] != '-') compteur++;
				else continue;
			}
    	}
		return (compteur==9) ? -1 : 0;
	}
}

/** Print Game Over Message **/
void printGameOverMessage(char name[LENGTH_NAME])
{
	printf("Game Over, \033[0;36m %s \033[0m is the winner. Good Job  \033[0;36m %s \033[0m.\n\n", name, name);
}

/** Print Message when No Winner **/
void printMessageWhenNoWinner(char * tab[])
{
	printf("Print the new game board...\n");
    printBoard(tab, LENGTH);
}

/** Print Message When No Case Available **/
void printMessageWhenNoCaseAvailable(char * tab[])
{
	printBoard(tab, LENGTH);
	printf("\033[1;31m Game Over, anyone of you won... \033[0m \n");
}

