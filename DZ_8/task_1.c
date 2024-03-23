/*
E1 ДЗ 1
Среднее арифметическое чисел
Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива. 

Данные на входе:     5 целых ненулевых чисел через пробел 
Данные на выходе:   Одно число в формате "%.3f" 
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

void Mean_Array(int arr[], int s)// функция вывода среднего арифметического данных массива
{
    int i;
    float mean = 0;
    for (i = 0; i < s; i++)
        mean += arr[i] / (float)s;
    printf("%.3f\n", mean);
}

int main(void)
{
    enum {SIZE = 5}; //указание количества элементов массива
    int arr[SIZE];//объявление массива
    Input_Array(arr, SIZE);
    Print_Array(arr, SIZE);
    Mean_Array(arr, SIZE);
    return 0;
}