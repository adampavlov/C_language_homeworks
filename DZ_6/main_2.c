// поиск четных и нечетных цифр числа
#include <stdio.h>

unsigned int a; 

void EvenOddCounter(unsigned int x)
{
    int even = 0, odd = 0;
    if (x==0)
        even = 1;
    while (x > 0)
        {
            int b = x % 10;
            if ((b % 2) == 0)
                even++;
            else 
                odd++;
            x /= 10;
        }
    printf("Even = %d\nOdd = %d\n", even, odd);
}

int main(void)
{
    scanf("%d",&a);
    printf("%d\n", a);
    EvenOddCounter(a);
    return 0;
}