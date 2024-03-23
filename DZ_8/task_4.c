/*
E13 ДЗ 5
Вторая с конца ноль 
Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль. 

Данные на входе: 		10 целых чисел через пробел. 
Данные на выходе: 	Целые числа через пробел, у которых вторая с конца цифра - ноль 

Пример
Данные на входе: 		40 105 203 1 14 1000 22 33 44 55 
Данные на выходе: 	105 203 1 1000 
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

void Sort_Array(int arr[], int s)// функция вывода чисел из массива, у которых десятки равны 0
{
    int i;
    int num;
    for (i = 0; i < s; i++)
    {
        num = arr[i]/10;
        if (num % 10 == 0)
            printf("%5d", arr[i]);// вывод элемента массива
    }  
    printf(";\n");
}

int main(void)
{
    enum {SIZE = 10}; //указание количества элементов массива
    int arr[SIZE];//объявление массива
    Input_Array(arr, SIZE);
    Print_Array(arr, SIZE);
    Sort_Array(arr, SIZE);
    return 0;
}