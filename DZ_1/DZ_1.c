#include <stdio.h>

int main(void)
{
    float a, b, c, x1_re, x2_re, x1_im, x2_im, D;
    printf("Hello, World!\n");// вывод на экран привествия
    printf("Let's\n");// пример использования табуляции
    printf("\t go\n");
    printf("\t\t to walk\n");
    printf("\n");
    printf("   *\n");
    printf("  ***\n");
    printf(" *****\n");
    printf("*******\n");
    printf(" HH HH\n");
    printf(" ZZZZZ\n");
    printf("\n");
    printf("Eto programma dlya resheniz kvadratnogo uravnenia \n");
    printf("\n");
    printf("Vvedite koefficienty a, b, c: ");
    scanf("%f %f %f",&a, &b, &c);
    printf("%.2fx^2 + %.2fx + (%.2f) = 0 \n", a, b, c);
    D = b*b - 4*a*c;
        if (D > 0)
        {
            x1_re = (-b + sqrt(D))/(2*a);
            x2_re = (-b - sqrt(D))/(2*a);
            printf("x1 = %.2f; x2 = %.2f.", x1_re, x2_re);
        }
        else 
        {
            printf("Veshestvennyh korney net!\n");
            x1_re = (-b)/(2*a) ;
            x1_im = sqrt((-1)*D)/(2*a);
            x2_re = (-b)/(2*a) ;
            x2_im = (-1)*sqrt((-1)*D)/(2*a);
            printf("x1 = %.2f +(%.2f)j; x2 = %.2f+(%.2f)j.", x1_re, x1_im, x2_re, x2_im);
        }
    return 0;
}