#include <stdio.h>

int main(void)
{
    int a, b, c;
    printf("Programma nahodit summu i proizvedenie 3 celyh chisel \n");
    printf("Vvedite 3 celyh chisla: \n");
    scanf("%d %d %d", &a, &b, &c);
    printf("%d + %d + %d = %d \n", a, b, c, a+b+c);
    printf("%d * %d * %d = %d \n", a, b, c, a*b*c);
    return 0;
}