#include "morpion.c"


int main()
{
    char * tab[LENGTH], * name[LENGTH_NAME], gamePiece[LENGTH_PIECE];
    short int play_is_ok, player_1, player_2, isWinner;
    play_is_ok = 0;
    player_1 = 0;
    player_2 = 0;
    isWinner = 0;

    bookPlace2x2(tab, LENGTH);

    printf("Initialize the game board...\n");
    initBoard(tab, LENGTH);

    bookPlace2x2(name, 2);
    config(name, gamePiece);
    

    printf("Print the game board...\n");
    printBoard(tab, LENGTH);

    player_1 = 1;
    do
    {
        if (player_1)
        {
            play_is_ok = playCase(tab, gamePiece[0], name[0]);
            if (play_is_ok) 
            {
                player_1 = 0;
                player_2 = 1;
                isWinner = winner(tab, LENGTH);
                if (isWinner == 0)
                    printMessageWhenNoWinner(tab);
                else if(isWinner == -1)
                    printMessageWhenNoCaseAvailable(tab);
                else 
                {
                    printBoard(tab, LENGTH);
                    printGameOverMessage(name[0]);
                }
            }
        }
        else if (player_2)
        {
            play_is_ok = playCase(tab, gamePiece[1], name[1]);
            if (play_is_ok) 
            {
                player_2 = 0;
                player_1 = 1;
                isWinner = winner(tab, LENGTH);
                if (isWinner == 0)
                    printMessageWhenNoWinner(tab);
                else if(isWinner == -1)
                    printMessageWhenNoCaseAvailable(tab);
                else 
                {
                    printBoard(tab, LENGTH);
                    printGameOverMessage(name[1]);
                }
            }
        }
        
    } while (isWinner==0);
    
    freePlace2x2(tab, LENGTH);
    freePlace2x2(name, 2);
    return 0;
}