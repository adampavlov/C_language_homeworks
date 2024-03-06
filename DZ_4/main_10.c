#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);
    if (x==1||x==2||x==12)
    {
        printf("Winter\n");
    }
    if (x==3||x==4||x==5)
    {
        printf("Spring\n");
    }
    if (x==6||x==7||x==8)
    {
        printf("Summer\n");
    }
    if (x==9||x==10||x==11)
    {
        printf("Autum");
    }
    return 0;
}