
/*
F6 ДЗ 4
Два одинаковых
Написать функцию и программу, демонстрирующую работу данной функции, которая определяет, верно ли, что среди элементов массива есть два одинаковых. Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:

int is_two_same(int size, int a[]);

Данные на входе:     Массив из целых чисел 
Данные на выходе:   Функция возвращает 1 или 0 

Пример №1
Данные на входе:     1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
Данные на выходе:   NO 
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

void Sort_Array(int *arr, int s)// функция сортировки пузырьком
{
    int i, j, num;
    for (i = 1; i < s; i++)
    {
        for (j = 0; j < s; j++)
        {
            if (arr[j] > arr[j+1])
            {
                num = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = num;
            }
        }
    } 
}

void Is_Two_Same(int s, int *arr)// функция, говорящая о дублирующихся элементах массива
{
    int i;
    int count = 0;
    for (i = 1; i < s; i++)
    {
        if (arr[i-1] == arr[i])
            count = count + 1;
    }
    if (count > 0 )
        printf("YES\n");
    if (count == 0)
        printf("NO\n");
}

int main(void)
{
    enum {SIZE = 5}; //указание количества элементов массива
    int arr[SIZE];//объявление массива
    Input_Array(arr, SIZE);
    Print_Array(arr, SIZE);
    Sort_Array(arr, SIZE);
    Print_Array(arr, SIZE);
    Is_Two_Same(SIZE, arr);
    return 0;
}