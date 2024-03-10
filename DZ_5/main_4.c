#include <stdio.h> 

int main(void) 
{ 
    int a, rev, buf;
    rev = 0; 
    scanf("%d", &a); 
    while (a > 0)
    {
        buf = a % 10;
        rev = rev*10 + buf;
        a /= 10;
    }
    printf("%d", rev);
    return 0; 
}
