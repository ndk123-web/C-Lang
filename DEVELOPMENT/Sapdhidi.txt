#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void check(int *p1)
{
    // Ladders
    if (*p1 == 5)
        *p1 = 44;
    if (*p1 == 8)
        *p1 = 32;
    if (*p1 == 20)
        *p1 = 81;
    if (*p1 == 38)
        *p1 = 79;
    if (*p1 == 78)
        *p1 = 97;
    if (*p1 == 52)
        *p1 = 90;

    // Snakes
    if (*p1 == 99)
        *p1 = 10;
    if (*p1 == 96)
        *p1 = 74;
    if (*p1 == 75)
        *p1 = 48;
    if (*p1 == 51)
        *p1 = 9;
    if (*p1 == 36)
        *p1 = 6;
    if (*p1 == 58)
        *p1 = 4;
}

int random(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    int p1 = 1, p2 = 1; 
    int box[10][10];    
    int c = 1;          

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            box[i][j] = c++;
        }
    }

    // Game loop
    while (p1 <= 100)
    {
        int ch;
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Player 1 Rolls \t");
            int diceval = random(1, 6); 

            p1 += diceval; 
            if (p1 > 100)
            {
                p1 = p1 - diceval;
            }
          
            printf("Current Location %d\t", p1);

            check(&p1);

            printf("Updated Location: %d\tDice Value %d\n", p1, diceval);
              if (p1 == 100)
            {
                printf("\n*********Player 1 Wins***********");
            }
        }
            int c;
            scanf("%d",&c);
            if(c==1){
            printf("Player 2 Rolls \t");

            int diceval1 = random(1, 6);
            p2 = p2 + diceval1;
            if (p2 > 100)
            {
                p2 = p2 - diceval1;
            }
            
            printf("Current Location %d\t", p2);

            check(&p2); 

            printf("Updated Location: %d\tDice Value %d\n", p2, diceval1);
            if (p2 == 100)
            {
                printf("\n*********Player 2 Wins**********\n");
                break;
            }
            }
        }
        return 0;
    }
