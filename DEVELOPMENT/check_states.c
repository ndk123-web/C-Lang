#include <stdio.h>
#include <string.h>

void main()
{
    char a[100];
    char state[][3] = {"AN", "AP", "AR", "AS", "BR", "CH", "CG", "DD", "DL", "GA", "GJ", "HR", "HP", "JK", "JH", "KA", "KL", "LA", "LD", "MP", "MH", "MN", "ML", "MZ", "NL", "OD", "PY", "PB", "RJ", "SK", "TN", "TS", "TR", "UP", "UK", "WB"};

    char s[][50] = {"Andaman and Nicobar Islands", "Andhra Pradesh", "Arunachal Pradesh", "Assam", "Bihar", "Chandigarh", "Chhattisgarh", "Dadra and Nagar Haveli and Daman and Diu", "Delhi", "Goa", "Gujarat", "Haryana", "Himachal Pradesh", "Jammu and Kashmir", "Jharkhand", "Karnataka", "Kerala", "Ladakh", "Lakshadweep", "Madhya Pradesh", "Maharashtra", "Manipur", "Meghalaya", "Mizoram", "Nagaland", "Odisha", "Puducherry", "Punjab", "Rajasthan", "Sikkim", "Tamil Nadu", "Telangana", "Tripura", "Uttar Pradesh", "Uttarakhand", "West Bengal"};

    char ch[100];
    int i;
    printf("Enter Car Number");
    scanf("%s", a);

    for (i = 0; i < 2; i++)
    {
        ch[i] = a[i];
    }
    ch[2] = '\0';
    int f = 0;
    for (i = 0; i < 36 ; i++)
    {
        if (strcmp(ch, state[i]) == 0)
        {
            f = 1;
            printf("States is %s", s[i]);
            break;
        }
    }
    if (f == 0)
    {
        printf("State not found");
    }
}