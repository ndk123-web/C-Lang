#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[3][2][2] = {{{1, 2}, {3, 4}},                
                      {{6, 7}, {8,9}},                                      
                      {{5, 2}, {7, 9}}};                                    

    int(*p)[2][2];
    p = a;

    printf("%d\n", p);
    printf("%d\n", *p);
    printf("%d\n", *(*p));                                                              
    printf("%d\n", *(*(*p)));

    printf("%d\n", (*(p[2][0])));
    printf("%d\n", (*(p[2][0] + 1)));
    printf("%d\n",*(p[1][1]+1));
    printf("%d\n",*(*p[0]+3));


}