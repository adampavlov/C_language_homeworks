// если сумма цифр числа равна 10, то пишется YES, иначе NO
#include <stdio.h>

unsigned int a; 

void Summ(unsigned int x)
{
    int sum = 0;
    while (x > 0)
        {
            int b = x % 10;
            sum += b;
            x /= 10;
        }
    if (sum != 10)
        printf("NO\n");
    else
        printf("YES\n");
}

int main(void)
{
    scanf("%d",&a);
    printf("%d\n", a);
    Summ(a);
    return 0;
}