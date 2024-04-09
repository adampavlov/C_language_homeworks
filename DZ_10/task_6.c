
/*
G18
Удалить пробелы из текста
В файле .txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы). Для решения задачи разработать функцию. Результат записать в .txt. 

Данные на входе:     Строка из английских букв, знаков препинания и пробелов. Не более 1000 символов. 
Данные на выходе:   Строка из английских букв, знаков препинания и пробелов. 


Пример
Данные на входе:      Hello world! 
Данные на выходе:   Hello world!
*/


#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001
const char *IN_FILE = "In_task_6.txt";
const char *OUT_FILE = "Out_task_6.txt";

/*
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
*/

int First_Symbol_Index(char *arr, int size)// функция определяет индекс последнего пробела в начале исходного массива
{
    int i, first_symbol_index;
    first_symbol_index = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] != ' ') break;
        first_symbol_index = i;
    }
    return first_symbol_index;
}

void Start_Clean(char *arr, char *out, int size, int start_index)// функция возвращает массив без пробелов в начале
{
    int i, j = 0;
    if (start_index > 0)// иначе будет пропадать первая буква, когда исходная строка начинается не с пробела
    {
        start_index++;
    }
    
    for (i = start_index; i < size; i++)
    {
            out[j] = arr[i];
            j++;
    }
}

void All_Clean(char *arr, char *out, int size)// функция возвращает массив без двойных пробелов
{
    int i, j = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == ' ' && arr[i] == arr[i + 1]) //если встречается два пробела подряд, то записывается в выходной массив, только один пробел
        {
            out[j] = arr[i + 1];
            j++;
            i++;
        }
        else // в противном случае в выходной массив записавется текущий символ
        {
            out[j] = arr[i];
            j++;
        }
        
    }
}

/*
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
*/

int main(void)
{
    FILE *f;
    char Arr[MAX_LENGTH] = {0};
    f = fopen(IN_FILE, "r");// файл заканчивается пробелом
    fscanf(f, "%[^\n]", Arr);
    fclose(f);
    //printf("%s\n", Arr);
    int first_index = First_Symbol_Index(Arr, MAX_LENGTH);
    //printf("Index first symbol = %d\n", first_index);// 
    int length = MAX_LENGTH - (first_index + 1);
    char Arr1[length];
    Start_Clean(Arr, Arr1, MAX_LENGTH, first_index);
    //printf("%s\n", Arr1);
    char Out[length];
    All_Clean(Arr1, Out,length);
    //printf("%s\n", Out);
    f = fopen(OUT_FILE, "w");
    int i;
    for (i = 0; i < length; i++)// запись по буквам самого длинного слова
        fprintf(f, "%c", Out[i]);
    fclose(f);
    return 0;
}
