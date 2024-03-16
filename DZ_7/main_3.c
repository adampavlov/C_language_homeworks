/*
Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.
Данные на входе:                 Натуральное число
Данные на выходе:         Целое число - количество единиц в двоичной записи числа.

Пример №1
Данные на входе:                 5
Данные на выходе:         2
*/
#include <stdio.h>

int print_ones(int num)
{
    static int c = 0;
    if (num > 0)
    {
        print_ones(num/2);
        c += num%2;
    }
    return c;   
}

int main(void)
{
    int a;
    printf("Vedite chislo:\n");
    scanf("%d", &a);
    printf("%d\n", a);
    printf("%d", print_ones(a));
    return 0;
}