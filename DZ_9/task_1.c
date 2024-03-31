/*
F5 ДЗ 3
Максимум в массиве
Написать функцию и программу, демонстрирующую работу данной функции, которая находит максимальный элемент в массиве. 

Прототип функции:
int find_max_array(int size, int a[])

Данные на входе:     Массив состоящий из целых чисел. Первый аргумент, размер массива, второй аргумент адрес нулевого элемента. 
Данные на выходе:   Одно целое число 
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

int Find_Max_Array(int s, int *arr)// функция вывода максимума среди данных массива
{
    int i;
    int max;
    max = arr[0];
    for (i = 0; i < s; i++)
    {
        max = arr[i] > max ? arr[i]:max;
    }
    printf("Array maximum = %d\n", max);
}

int main(void)
{
    enum {SIZE = 5}; //указание количества элементов массива
    int arr[SIZE];//объявление массива
    Input_Array(arr, SIZE);
    Print_Array(arr, SIZE);
    Find_Max_Array(SIZE, arr);
    return 0;
}