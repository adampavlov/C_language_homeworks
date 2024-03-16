/*
От A до B
Составить рекурсивную функцию.
Выведите все числа от A до B включительно, в порядке возрастания, если A < B,
или в порядке убывания в противном случае.  

Данные на входе:                 Два целых числа через пробел.
Данные на выходе:         Последовательность целых чисел.
*/

#include <stdio.h>

void print_num(int num1, int num2)
{
    if (num1 < num2)
    {
        print_num(num1, num2 -1);
        printf("%d; ", num2); 
    }
    if (num1 > num2)
    {
        printf("%d; ", num1);
        print_num(num1 -1 , num2);
    }
    if (num1 == num2)
    printf("%d; ", num1);
}

int main(void)
{
    int A, B;
    printf("Vedite chislo A, B:\n");
    scanf("%d%d", &A, &B);
    printf("Chislo A = %d, B = %d\n", A, B);
    print_num(A, B);
    return 0;
}