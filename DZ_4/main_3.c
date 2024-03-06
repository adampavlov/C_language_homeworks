#include <stdio.h>

int main(void)
{
    int X, a, b, c, max;
    scanf("%d",&X);
    a = X/100;
    b = X/10 -10*a;
    c = X - 100*a - 10*b;
    
    if (a>b)
    {
        if (a>c)
        {
            max = a;
            printf("%d", max);
        }
        else
        {
            max = c;
            printf("%d", max);
        }
    }
    else
    {
        if (b>c)
        {
            max = b;
            printf("%d", max);
        }
        else
        {
            max = c;
            printf("%d", max);
        }
    }
    return 0;
}