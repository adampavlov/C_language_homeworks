#include <stdio.h>

int main(void)
{
    int a, b, i, sum;
    sum = 0;
    scanf("%d%d", &a, &b);
    if (a <= b)
    {
        for ( i = a; i <= b; i++)
        {
            sum += i*i;
        }
    printf("%d\n", sum);
    }
    else
    {
        printf("Exit\n");
    }
    return 0;
}