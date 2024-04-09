
/*
Самое длинное слово
В файле .txt дана строка слов, разделенных пробелами.
Найти самое длинное слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть несколько, не обрабатывать. 

Данные на входе:     Строка из английских букв и пробелов. Не более 1000 символов. 
Данные на выходе:   Одно слово из английских букв. 

Пример
Данные на входе:     Hello beautiful world 
Данные на выходе:   beautiful
*/


#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001
const char *IN_FILE = "In_task_5.txt";
const char *OUT_FILE = "Out_task_5.txt";

int Space_Counter(char *arr)// функция подсчитывает пробелы, которые есть разделители слов
{
    char *str = &arr[0];
    int  i = 0;
    while (*str != '\0')
    {
        if ((*str == 32))
            i++;
        *str++;
    }
    return i;
}

void Space_Index(char *arr, int *out, int size)// функция определяет индексы пробелов в исходном массиве
{
    int i, j;
    j = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == 32)
        {
            out[j] = i;
            j++;
        }
        
    }
}

void Word_Length(int *arr, int *out, int size)// функция подсчитывает длину слов и записывает длины в массив
{
    int i, j;
    j = 0;
    for (i = 0; i < size - 1; i++)
    {
        if (i == 0)
        {
            out[j] = arr[i];
            j++;
        }
        out[j] = arr[i+1]-arr[i] - 1;
        j++;
    }
}

int Max(int *arr, int size)// функция возвращает 
{
    int max = arr[0];
    int i, ind_max;
    for (i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        
    }
    for (i = 0; i < size; i++)
    {
            if (arr[i] == max)
            {
                ind_max = i;
            }
        
    } 
    return ind_max;
}


int main(void)
{
    FILE *f;
    char str[MAX_LENGTH] = {0};
    f = fopen(IN_FILE, "r");// файл заканчивается пробелом
    fscanf(f, "%[^\n]", str);
    fclose(f);

    int space_count = Space_Counter(str);
    int str2[space_count];
    Space_Index(str, str2, MAX_LENGTH);
    int str3[space_count];
    Word_Length(str2, str3, space_count);// массив из длинн слов
    Max(str3, space_count);// индекс максимально длинного слова в массиве, состоящих из длинн слов
    int k, start = 0;// start - индекс начала самого длинного слова в исходном массиве
    for ( k = 0; k < Max(str3, space_count); k++)
    {
        start += str3[k];
    }
    start += Max(str3, space_count);
    int fin = start + str3[Max(str3, space_count)];// fin - индекс конца самого длинного слова в исходном массиве + 1
    char out[Max(str3, space_count)];
    f = fopen(OUT_FILE, "w");
    int y;
    for (y = start; y < fin; y++)// запись по буквам самого длинного слова
        fprintf(f, "%c", str[y]);
    fclose(f);
    return 0;
}
