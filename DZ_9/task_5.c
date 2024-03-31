/*F14
Сумма в интервале
Написать функцию и программу, демонстрирующую работу данной функции, которая возвращает сумму элементов в заданном отрезке [from, to] для массива. Прототип функции
int sum_between_ab(int from, int to, int size, int a[]) 

Данные на входе: 		Функция принимает концы отрезка from и to, размер массива, массив целых чисел 
Функция возвращает сумму элементов в интервале [from, to] 

Пример №1
Данные на входе: 		6 4 1 2 3 4 5 6 7 8 9 10 
Данные на выходе: 	15 

Примечание — Интервал 4 6 числа 4 5 6 к-во 3 сумма 15
*/
#include <stdio.h>

int Input_Array(int *arr, int s)// функция ввода массива
{
    int i;
    for (i = 0; i < s; i++) 
        scanf ("%d", &arr[i]);// ввод значений
    return i;
}

void Print_Array(int *arr, int L)// функция вывода данных массива
{
    int i;
    printf("ARRAY[%d] = ", L);
    for (i = 0; i < L; i++)
        printf("%5d", arr[i]);// вывод элемента массива
    printf(";\n");
}

int sum_between_ab(int from, int to, int size, int *arr)// функция вывода максимума среди данных массива
{
    int i, sum;
    sum = 0;
    for ( i = from + 1; i < to + 2; i++)
    {
        sum += arr[i];
    }
    printf("Summa = %d.\n", sum);

}

int main(void)
{
    enum {SIZE = 12}; //указание количества элементов массива
    int arr[SIZE];//объявление массива
    int from, to;
    from = 4;
    to = 6;
    Input_Array(arr, SIZE);
    Print_Array(arr, SIZE);
    sum_between_ab(from, to, SIZE, arr);
    return 0;
}
