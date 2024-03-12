// поиск минимальной и максимальной цифры в числе
#include <stdio.h>

unsigned int a; 
void MinMax(unsigned int x)
{
    unsigned int min, max;
    max = 0;
    while (x > 0)
        {
            int b = x % 10;
            max = max < b ? b : max;
            min = min > b ? b : min;
            x /= 10;
        }
    printf("%d\n%d\n", min, max);
}

int main(void)
{
    scanf("%d",&a);
    printf("%d\n", a);
    MinMax(a);
    return 0;
}