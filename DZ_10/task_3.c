
/*
G8 ДЗ 3
Числа в массив
В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы. Требуется все числа,
которые встречаются в строке, поместить в отдельный целочисленный массив.
Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
Вывести массив по возрастанию в файл .txt. 

Данные на входе:     Строка из английских букв, цифр и знаков препинания 
Данные на выходе:   Последовательность целых чисел отсортированная по возрастанию 

Пример
Данные на входе:     data 48 call 9 read13 blank0a 
Данные на выходе:   0 9 13 48
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001
const char *IN_FILE = "In_task_3.txt";
const char *OUT_FILE = "Out_task_3.txt";

int Numbers(char *arr, int *out)// функция записывает в целочисленный массив все числа, которые найдены в символьной строке
{
    char *str = &arr[0];// адрес начала строки = первый элемент массива из файла
    int number, count = 0;
    while (*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
        {
            number = atoi(str);// если строка начинается с цифры, то atoi преобразует строку в число до тех пор, пока не встретится символ-нецифра
            out[count++] = number;
        }
        *str++;
    }
    return count;
}

void Sort(int size, int *arr)
{
    int temp, i, j;
    for (i = 0; i < size; ++i)
    {
        for (j = size - 1; j > i; --j)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(void)
{
    FILE *f;
    char str[MAX_LENGTH] = {0};
    int numbers[MAX_LENGTH] = {0};
    int num_count = 0;
    f = fopen(IN_FILE, "r");
    fscanf(f, "%[^\n]", str);
    fclose(f);
    num_count = Numbers(str, numbers);
    Sort(num_count, numbers);
    f = fopen(OUT_FILE, "w");
    int i;
    for (i = 0; i < num_count; ++i)
        fprintf(f, "%d ", numbers[i]);
    fclose(f);
    return 0;
}
