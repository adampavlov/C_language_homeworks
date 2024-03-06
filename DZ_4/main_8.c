#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, min;
    scanf("%d %d %d %d %d",&a, &b, &c, &d, &e);
    min = a;
    min = min>b ? b:min;
    min = min>c ? c:min;
    min = min>d ? d:min;
    min = min>e ? e:min;
    printf("%d\n",min);
    return 0;
}