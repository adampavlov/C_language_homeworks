#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, max, min;
    scanf("%d %d %d %d %d",&a, &b, &c, &d, &e);
    max = a;
    max = max<b ? b:max;
    max = max<c ? c:max;
    max = max<d ? d:max;
    max = max<e ? e:max;
    min = max;
    min = min>a ? a:min;
    min = min>b ? b:min;
    min = min>c ? c:min;
    min = min>d ? d:min;
    min = min>e ? e:min;
   
    printf("%d\n%d\n",max, min);
    return 0;
}