/*
Только один раз
Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран. 

Данные на входе:     10 целых чисел 
Данные на выходе:   Элементы которые встречаются только один раз 
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

void Sort_Array(int arr[], int s)// функция сортировки пузырьком
{
    int i, j, num;
    for (i = 1; i < s; i++)
    {
        for (j = 0; j < s; j++)
        {
            if (arr[j]>arr[j+1])
            {
                num = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = num;
            }
        }
    } 
}

void No_Repeat(int arr[], int s)// функция вывода неповторяющихся элементов массива
{
    int i;
    printf("No repeat numbers in array:");
    for (i = 0; i < s; i++)
    {
        if ((arr[i-1] != arr[i]) && (arr[i] != arr[i+1]))
            printf("%5d; ", arr[i]);
    }
}


int main(void)
{
    enum {SIZE = 10}; //указание количества элементов массива
    int arr[SIZE];//объявление массива
    Input_Array(arr, SIZE);
    Print_Array(arr, SIZE);
    Sort_Array(arr, SIZE);
    //Print_Array(arr, SIZE);
    No_Repeat(arr, SIZE);
    return 0;
}