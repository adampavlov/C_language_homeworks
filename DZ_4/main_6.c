#include <stdio.h>

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    if (x>y)
    {
        printf("Above\n");
    }
    if (x<y)
    {
       printf("Less\n"); 
    }
    if (x==y)
    {
        printf("Equal\n");
    }
    return 0;
}