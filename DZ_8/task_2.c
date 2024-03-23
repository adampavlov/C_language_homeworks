/*
E5
Сумма положительных элементов
Считать массив из 10 элементов и подсчитать сумму положительных элементов массива. 

Данные на входе: 		10 целых чисел через пробел 
Данные на выходе: 	Одно целое число - сумма положительных элементов массива 

Пример №1
Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0 
Данные на выходе: 	26 
*/
#include <stdio.h>

int Input_Array(int arr[], int s)// функция ввода массива
{
    int i;
    for (i = 0; i < s; i++) 
        scanf ("%d", &arr[i]);// ввод значений
    return i;
}

void Print_Array(int arr[], int L)// функция вывода данных массива
{
    int i;
    printf("ARRAY[%d] = ", L);
    for (i = 0; i < L; i++)
        printf("%5d", arr[i]);// вывод элемента массива
    printf(";\n");
}

void Pos_Sum(int arr[], int s)// функция вывода среднего арифметического данных массива
{
    int i, sum;
    sum = 0;
    for (i = 0; i < s; i++)
        if (arr[i]>0)
            sum += arr[i];
    printf("Summa = %d\n", sum);
}

int main(void)
{
    enum {SIZE = 10}; //указание количества элементов массива
    int arr[SIZE];//объявление массива
    Input_Array(arr, SIZE);
    Print_Array(arr, SIZE);
    Pos_Sum(arr, SIZE);
    return 0;
}