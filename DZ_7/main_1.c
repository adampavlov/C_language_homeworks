/*
В прямом порядке
Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками.
 Необходимо реализовать рекурсивную функцию.
void print_num(int num)
*/

#include <stdio.h>

void print_num(int num)
{
    if (num/10 > 0)
        print_num(num/10);
    num %= 10;  
    printf("%d; ", num);
}

int main(void)
{
    int a;
    printf("Vedite chislo:\n");
    scanf("%d", &a);
    print_num(a);
    return 0;
}