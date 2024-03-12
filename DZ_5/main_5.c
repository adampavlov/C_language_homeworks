#include <stdio.h>

unsigned int a; 

void SumMult(unsigned int x)
{
    int i, j;
        for (i = x; i>10; i--)
    {
        j = i;
        int summ = 0;
        int mult = 1;
        while (j>0)
        {
            int b = j % 10;
            summ += b;
            mult *= b;
            j /= 10;
        }
        if (summ == mult)
        printf("  %d", i);
    }
}

int main(void)
{
    scanf("%d",&a);
    printf("%d\n", a);
    SumMult(a);
    return 0;
}