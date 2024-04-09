/*
Удалить повторяющиеся символы
В файле .txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл .txt. 

Данные на входе:     Строка из меленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более 1000 сивмолов. 
Данные на выходе:   Строка из меленьких и больших английских букв. 

Пример
Данные на входе:     abc cde def 
Данные на выходе:   abcdef
*/


#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001
const char *IN_FILE = "In_task_4.txt";
const char *OUT_FILE = "Out_task_4.txt";

int WordCounter(char *arr)// функция записывает в массив только буквы, которые найдены в символьной строке
{
    char *str = &arr[0];// адрес начала строки = первый элемент массива из файла
    int  i = 0;
    while (*str != '\0')
    {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
            i++;
        *str++;
    }
    return i;
}

void WordFilter(char *arr, char *out)
{
    char *str1 = &arr[0];
    char *str2 = &out[0];
    int i;
    while (*str1 != '\n')
    {
        if ((*str1 >= 'A' && *str1 <= 'Z') || (*str1 >= 'a' && *str1 <= 'z'))
        {
            *str2 = *str1;
            *str2++; 
        }
        str1++;
    }
    
}


int main(void)
{
    FILE *f;
    char str[MAX_LENGTH] = {0};
    f = fopen(IN_FILE, "r");
    fscanf(f, "%[^\n]", str);
    fclose(f);
    int length_word = WordCounter(str);
    char str2[length_word];
    WordFilter(str, str2);
    f = fopen(OUT_FILE, "w");
    int i;
    for (i = 0; i < length_word; i++)
        fprintf(f, "%c", str2[i]);
    fclose(f);
    
    return 0;
}
