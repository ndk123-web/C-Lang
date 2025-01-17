#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Employee
{
    char id[50];
    float sal;
    char name[50];
}Employee;

void check(Employee *e, char *cid, int c)
{
    for (int i = 0; i < c; i++)
    {
        if (strcmp(e[i].id, cid) == 0)
        {
            printf("Name : %s\n ", e[i].name);
            printf("Id : %s\n", e[i].id);
            printf("Salary : %f\n", e[i].sal);
        }
        else
            printf("Not Found\n");
    }
}

int main()
{
     Employee e[50];
    int ch, i, c = 0;
    char cid[50];

    while (1)
    {
        printf("1.Enter Details\n2.Check\n3.Exit\n");
        printf("Enter Choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Name : ");
            scanf("%s", &e[c].name);
            printf("Enter Id : ");
            scanf("%s", &e[c].id);
            printf("Enter Salary : ");
            scanf("%f", &e[c].sal);
            c++;
            break;

        case 2:
            printf("Enter Id to Find Details");
            scanf("%s", &cid);
            check(e, cid, c);
            break;

        case 3:
            return 0;
            break;

        default:
            printf("Invalid Option\n");
            break;
        }
    }
}