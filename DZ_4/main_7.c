#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, max;
    scanf("%d %d %d %d %d",&a, &b, &c, &d, &e);
    max = a;
    max = max<b ? b:max;
    max = max<c ? c:max;
    max = max<d ? d:max;
    max = max<e ? e:max;
    printf("%d\n",max);
    return 0;
}