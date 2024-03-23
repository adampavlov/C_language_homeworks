/*
E10 ДЗ 3
Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента. 

Данные на входе:     12 целых чисел через пробел 
Данные на выходе:   12 целых чисел через пробел 
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

void Shift_Right_Array(int arr[], int s, int k)// функция вывода среднего арифметического данных массива
{
    int i;
    int arr2[s];
    printf("Shift Array[%d] = ", s);
    for (i = 0; i < s; i++)
    {
        if (i < k)
        {
            arr2[i] = arr[s - k + i];
        }
        else
        {
            arr2[i] = arr[i - 4];
        }   
        printf("%5d", arr2[i]);// вывод элемента массива
    }  
    printf(";\n");
}

int main(void)
{
    enum {SIZE = 12}; //указание количества элементов массива
    int arr[SIZE];//объявление массива
    int shift = 4;//размер циклического сдвига значений массива
    Input_Array(arr, SIZE);
    Print_Array(arr, SIZE);
    Shift_Right_Array(arr, SIZE, shift);
    return 0;
}