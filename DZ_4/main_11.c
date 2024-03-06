#include <stdio.h>

int main(void)
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x+y>z && x+z>y && y+z>x)
    {
        printf("YES\n");
    }
    else
    {
       printf("NO\n"); 
    }
    return 0;
}