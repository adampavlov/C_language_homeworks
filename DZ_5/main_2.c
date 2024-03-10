#include <stdio.h>

int main(void)
{
    int a, th_min, th_max;
    th_min = 100;
    th_max = 999;
    scanf("%d", &a);
    if ( (a - th_min) >= 0 && (a - th_max)<=0)
    {
    printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}