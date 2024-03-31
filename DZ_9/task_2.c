/*
F2 ДЗ 2
Четные в начало
Написать функцию и программу, демонстрирующую работу данной функции,
которая ставит в начало массива все четные элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел между собой.
Строго согласно прототипу:
void sort_even_odd(int n, int a[])

Данные на входе:     Функция принимает на вход целые числа 
Данные на выходе:   Отсортированный исходный массив 
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

void sort_even_odd(int s, int *arr)// функция сортировки данных массива
{
    int i, j, k, len_odd, len_no_odd;
    len_no_odd = 0;
    for (i = 0; i < s; i++)
    {
        if (arr[i] % 2)//проверка на четность
            len_no_odd++;
    }
    len_odd = s - len_no_odd;
    int arr_odd[len_odd];
    int arr_no_odd[len_no_odd];
    printf("Quantity odd = %d, no odd = %d;\n",len_odd, len_no_odd);
    j = 0;
    k = 0;
    for (i = 0; i < s; i++)
    {
        if (arr[i] % 2)
        {
            arr_no_odd[k] = arr[i]; 
            k++;
        }
        else
        {
            arr_odd[j] = arr[i]; 
            j++;
        }
    }
    for (i = 0; i < s; i++)
    {
        if (i < len_odd)
        {
            arr[i] = arr_odd[i];
        }
        else
        {
            arr[i] = arr_no_odd[i-len_odd];
        }
    }
}

int main(void)
{
    enum {SIZE = 5}; //указание количества элементов массива
    int arr[SIZE];//объявление массива
    Input_Array(arr, SIZE);
    Print_Array(arr, SIZE);
    sort_even_odd(SIZE, arr);
    Print_Array(arr, SIZE);
    return 0;
}