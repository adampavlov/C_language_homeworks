/*
F9
Поменять местами
Написать функцию и программу, демонстрирующую работу данной функции,
которая в массиве находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива.
Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. 
Если отрицательных элементов нет - массив не менять.

Прототип функции:
void swap_negmax_last(int size, int a[])

Данные на входе:     Функция принимает на вход размер массива и указатель на начало массива. Массив состоит из целых чисел. 

Пример
Данные на входе:     1 -2 -3 -4 5 6 7 8 9 10 
Данные на выходе:   1 10 -3 -4 5 6 7 8 9 -2
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


void swap_negmax_last(int s, int *arr)
{
    
    int i, j, max_neg, count;
    count = 0;
    max_neg = -2147483647;
    for (i = 0; i < s; i++)
    {
        if (arr[i] < 0)
        count++;      
    }
    printf("Quantity negative numbers = %d\n", count); 
    if (count != 0)
    {
        for (i = 0; i < s; i++)
        {
            if (arr[i] < 0 && max_neg < arr[i])
            {
                max_neg = arr[i];
            }
            
        }
    }
    printf("Max negative = %d\n", max_neg); 
    int tmp = 0;
    for ( i = 0; i < s; i++)
    {
        if (arr[i] == max_neg)
        {
            tmp = arr[s-1];
            arr[s-1] = max_neg;
            arr[i] = tmp;
        }
        
    }
}

int main(void)
{
    enum {SIZE = 10}; //указание количества элементов массива
    int arr[SIZE];//объявление массива
    Input_Array(arr, SIZE);
    Print_Array(arr, SIZE);
    swap_negmax_last(SIZE, arr);
    Print_Array(arr, SIZE);
    return 0;
}