#include <stdio.h> 

int func(int x)
{
    while (x > 0) 
    { 
        x /= 10;
        if (x % 2) 
        {
            return 0;
        }
        return 1;
    }
}

int main(void) 
{ 
    int a; 
    scanf("%d", &a); 
    if (func(a))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0; 
}
