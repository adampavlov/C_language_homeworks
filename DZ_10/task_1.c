/*
G5 ДЗ 2
Заменить a на b
В файле .txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" и наоборот,
как заглавные, так и строчные. Результат записать в .txt. 

Данные на входе:     Строка из маленьких и больших английских букв, знаков препинания и пробелов. 
Данные на выходе:   Строка из маленьких и больших английских букв, знаков препинания и пробелов. 

Пример
Данные на входе:     aabbccddABCD 
Данные на выходе:   bbaaccddBACD
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001
const char *IN_FILE = "In_task_1.txt";
const char *OUT_FILE = "Out_task_1.txt";

void ChangeChars(char str[])// функция замены символов
{
    while (*str != '\0')
    {
        if (*str == 'a')
            *str = 'b';
        else if (*str == 'A')
            *str = 'B';
        else if (*str == 'b')
            *str = 'a';
        else if (*str == 'B')
            *str = 'A';
        str++;
    }
}

int main(void)
{
    FILE *f;
    char str[MAX_LENGTH] = {0};// пустой массив-буфер
    f = fopen(IN_FILE, "r");//открытие файла для чтения
    fscanf(f, "%[^\n]", str);// запись в str данных из открытого файла, запись идет словами, пока не происходит перенос строки
    fclose(f);// закрытие файла
    ChangeChars(str);
    f = fopen(OUT_FILE, "w"); // открытие файла для записи
    fprintf(f, "%s", str);// печать преобразованных строк в новый файл
    fclose(f);// закрытие файла
    return 0;
}