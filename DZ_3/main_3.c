#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Programma nahodit raznost` 2 celyh chisel \n");
    printf("Vvedite 2 celyh chisla: \n");
    scanf("%d %d", &a, &b);
    printf("%d - (%d) = %d \n", a, b, a-b);
    return 0;
}