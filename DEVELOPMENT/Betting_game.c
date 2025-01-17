#include <stdio.h>
#include <stdlib.h>

int cash = 100;

void play(int bet)
{
    char *c = (char *)malloc(3 * sizeof(char));
    c[0] = 'J';
    c[1] = 'Q';
    c[2] = 'K';
    int temp, x, y;
    for (int i = 0; i < 5; i++)
    {
        x = rand() % 3;
        y = rand() % 3;
        temp = c[x];
        c[x] = c[y];
        c[y] = temp;
    }
    int playerguess;
    printf("Enter Your Guess for Queen : 1,2,3,\n");
    scanf("%d", &playerguess);
    if (c[playerguess - 1] == 'Q')
    {
        cash = cash + 3 * bet;
        printf("You Win %d cash %c %c %c \n", cash, c[0], c[1], c[2]);
    }
    else
    {
        cash = cash - bet;
        printf("You loss %d cash %c %c %c \n", cash, c[0], c[1], c[2]);
    }
    free(c); // automatically deallcoate means heap mein free jageh hogi
}

void main()
{
    int bet;
    while (cash > 0)
    {
        printf("how many $ u want to bet?");
        scanf("%d", &bet);
        play(bet);
    }
}