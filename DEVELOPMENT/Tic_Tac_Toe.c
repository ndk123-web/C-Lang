#include <stdio.h>
#include <string.h>

int check1(char a[][3], char p1, int r, int c)
{
    a[r][c] = p1;
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] == p1 && a[i][1] == p1 && a[i][2] == p1)
        {
            printf("Player 1 Wins !! \n");
            return 0;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (a[0][i] == p1 && a[1][i] == p1 && a[2][i] == p1)
        {
            printf("Player 1 Wins !!\n");
            return 0;
        }
    }
    if (a[0][0] == p1 && a[1][1] == p1 && a[2][2] == p1)
    {
        printf("Player 1 Wins !!\n");
        return 0;
    }
    if (a[0][2] == p1 && a[1][1] == p1 && a[2][0] == p1)
    {
        printf("Player 1 Wins !!\n");
        return 0;
    }
    return 1;
}

int check2(char a[][3], char p2, int r, int c)
{
    a[r][c] = p2;
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] == p2 && a[i][1] == p2 && a[i][2] == p2)
        {
            printf("Player 2 Wins !! \n");
            return 0;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (a[0][i] == p2 && a[1][i] == p2 && a[2][i] == p2)
        {
            printf("Player 2 Wins !!\n");
            return 0;
        }
    }
    if (a[0][0] == p2 && a[1][1] == p2 && a[2][2] == p2)
    {
        printf("Player 2 Wins !!\n");
        return 0;
    }
    if (a[0][2] == p2 && a[1][1] == p2 && a[2][0] == p2)
    {
        printf("Player 2 Wins !!\n");
        return 0;
    }
    return 1;
}

void printboard(char a[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c\t", a[i][j]);
        }
        printf("\n");
    }
}

int checktie(char a[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    char p1 = 'O';
    char p2 = 'X';
    int f = 0;
    char board[3][3];
    int r1, c1, r2, c2;
    int i = 0, j = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    printf("Lets Start!!\n");

    while (1)
    {
        printf("Player 1 starts\n");

        while (1)
        {
            printf("Enter Location: (0-2) (0-2)");
            scanf("%d %d", &r1, &c1);
            if (r1 >= 0 && r1 <= 2 && c1 >= 0 && c1 <= 2 && board[r1][c1] == ' ')
            {
                break;
            }
            else
            {
                printf("Invalid Location\n");
            }
        }

        if (check1(board, p1, r1, c1) == 0)
        {
            printboard(board);
            break;
        }
        printboard(board);

        if (checktie(board))
        {
            printf("Game Tied !!\n");
            break;
        }

        printf("Player 2 Starts\n");
        while (1)
        {
            printf("Enter Location: (0-2) (0-2)");
            scanf("%d %d", &r2, &c2);

            if (r2 >= 0 && r2 <= 2 && c2 >= 0 && c2 <= 2 && board[r2][c2] == ' ')
            {
                break;
            }
            else
            {
                printf("Invalid Location\n");
            }
        }

        if (check2(board, p2, r2, c2) == 0)
        {
            printboard(board);
            break;
        }
        printboard(board);

        if (checktie(board))
        {
            printf("Game Tied !!\n");
            break;
        }
    }
    return 0;
}