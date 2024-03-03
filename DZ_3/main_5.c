#include <stdio.h>

int main(void)
{
    int a, x1, x2, x3;
    printf("Programma nahodit proizvedenie cifr 3-znacnogo chisla \n");
    printf("Vvedite 3-znacnoe polozhitel`noe chislo: \n");
    scanf("%d", &a);
    x1 = a/100;
    x2 = a/10 - x1*10;
    x3 = a - x1*100 - x2*10;
    printf("%d = %d , %d , %d; Proizvedenie cifr = %d \n", a, x1, x2, x3, x1*x2*x3);
    return 0;
}