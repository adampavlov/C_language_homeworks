#include <stdio.h>

int main(void)
{
    int a, b, c;
    printf("Programma nahodit srednee arifmeticheskoe 3 celyh chisel \n");
    printf("Vvedite 3 celyh chisla: \n");
    scanf("%d %d %d", &a, &b, &c);
    printf("(%d + %d + %d)/3 = %.2f \n", a, b, c, (a+b+c)/3.0);
    return 0;
}