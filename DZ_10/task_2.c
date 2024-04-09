/*
G4 ДЗ 1
По одному разу
В файле .txt даны два слова не более 100 символов каждое, разделенные одним пробелом.
Найдите только те символы слов, которые встречаются в обоих словах только один раз.r
Напечатайте их через пробел в файл .txt в лексикографическом порядке. 

Данные на входе:     Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов. 
Данные на выходе:   Маленькие английские буквы через пробел. 

Пример №1
Данные на входе:     hello world 
Данные на выходе:   o 


Данные на входе:     aabcd bcef 
Данные на выходе:   b c
*/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 101
const char *IN_FILE = "In_task_2.txt";
const char *OUT_FILE = "Out_task_2.txt";

const char *INPUT_FILE = "In_task_2.txt";
const char *OUTPUT_FILE = "Out_task_2.txt";
#define MAX_LENGTH 101

// Сортирует строку.
void sortString(char str[])
{
    char temp;
    int size = strlen(str);
    int i, j;
    for ( i = 0; i < size; ++i)
    {
        for ( j = size - 1; j > i; --j)
        {
            if (str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// Возвращает 1 если символ уже есть в массиве иначе 0.
int isExists(int size, char arr[], char c)
{
    int i;
    for ( i = 0; i < size; ++i)
    {
        if (arr[i] == c)
            return 1;
    }
    return 0;
}

/* Разделяет массив in на 2 слова и заполняет массив out символами из in,
которые встречаются в обоих словах только один раз.*/
void process(char in[], char out[])
{
    int in_len = strlen(in);
    int out_len = 0;

    // Индекс первого пробела (между словами)
    int space_index = -1;
    int k;
    for (k = 0; k < in_len; ++k)
    {
        if (in[k] == ' ')
        {
            space_index = k;
            break;
        }
    }

    // Подсчет каждого символа в каждом слове
    int count1, count2, i, j;
    for ( i = 0; i < in_len; ++i)
    {
        count1 = 0;
        count2 = 0;
        // Количество таких символов в первом слове
        for ( j = 0; j < space_index; ++j)
        {
            if (in[j] == in[i])
                count1++;
        }

        // Количество таких символов во втором слове
        for ( j = space_index + 1; j < in_len; ++j)
        {
            if (in[j] == in[i])
                count2++;
        }

        // Если символ один в каждом слове то добавляем его в результат, если его еще там нет
        
        if (count1 == 1 && count2 == 1 && isExists(out_len, out, in[i]) != 1)
            out[out_len++] = in[i];
        
    }
    out[out_len] = '\0'; // теперь это строка

    // Сортируем строку
    sortString(out);
}

int main(void)
{
    FILE *fp;
    char line[MAX_LENGTH * 2] = {0}, result[MAX_LENGTH] = {0};

    // Чтение строки из входного файла в line массив
    if ((fp = fopen(INPUT_FILE, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    fscanf(fp, "%[^\n]", line);
    fclose(fp);

    // Получение результата в массив result
    process(line, result);

    // Запись result в выходной файл
    if ((fp = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }
    int i;
    for ( i = 0; i < strlen(result); ++i)
        fprintf(fp, "%c ", result[i]);
    fclose(fp);

    return 0;
}