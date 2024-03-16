/*
Возвести в степень
Написать рекурсивную функцию возведения целого числа n в степень p.
int recurs_power(int n, int p)
Используя данную функцию, решить задачу.

Данные на входе:                 Два целых положительных числа
Данные на выходе:         Одно целое число n в степени p
*/

#include <stdio.h>

int recurs_power(int n, int p)
{
    if ( p == 0)
        return 1;
    if (p > 0)
        return n*recurs_power(n, p - 1); 
    return 0;
}

int main(void)
{
    int a, b;
    printf("Vedite chisla:\n");
    scanf("%d%d", &a, &b);
    printf("(%d)^(%d) = %d", a, b, recurs_power(a, b));
    return 0;
}