#include <stdint.h>
#include "temp_api.h"

// Функция читает csv файл, записывает данные в структуру типа sensor и возвращает количество корректных сделанных записей в структуру
int Read_CSV(char *Filename, sensor **Sensor_Data)
{
    FILE *f;
    f = fopen(Filename, "r"); // открываем файл
    if (!f)                   // если ошибка открытия то выходим из функции и сообщаем об этом
    {
        printf("ERORR OPEN FILE\n");
        return -1;
    }
    char Line[8 * 7];                    // выделяем буфер под чтение строк - 5 байт под данные в строке
    int Num_Records = 0;                 // счетчик количество записей в файле
    while (fgets(Line, sizeof(Line), f)) // чтение целой строки из файла f
    {
        sensor Record;                                                                                                                 // структуры для заполнения ее данными из файла
        if (sscanf(Line, "%d;%d;%d;%d;%d;%d", &Record.year, &Record.month, &Record.day, &Record.hour, &Record.minute, &Record.t) == 6) // если считали все параметры
        {
            (*Sensor_Data) = realloc(*Sensor_Data, sizeof(sensor) * (Num_Records + 1)); // то увеличиваем выделенную память на размер одного элемента структуры
            (*Sensor_Data)[Num_Records] = Record;                                       // иначе добавляем структуру в массив
            Num_Records++;                                                              // увеличиваем счётчик элементов в массиве
        }
        else
        {
            printf("IN STRING NUMBER %d ERORR DATA\n", Num_Records + 1); // если данные оказались битые, то выводится номер строки с данными
            printf("------------------------------------------\n");
        }
    }
    fclose(f);          // после чтения закрываем файл
    return Num_Records; // возвращаем количество элементов массива
}
// Функция вывода максимальной температуры за год (весь период наблюдения)
int Max_Temp(int *temp, int n)
{
    int i, max;
    max = temp[0];
    for (i = 0; i < n; i++)
        if (max < temp[i])
            max = temp[i];
    return max;
}
// Функция вывода минимальной температуры за год (весь период наблюдения)
int Min_Temp(int *temp, int n)
{
    int i, min;
    min = temp[0];
    for (i = 0; i < n; i++)
        if (min > temp[i])
            min = temp[i];
    return min;
}
// Функция вывода среднегодовой температуры (средней за весь период наблюдения)
int Avr_Temp(int *temp, int n)
{
    int i;
    float avr = 0;
    for (i = 0; i < n; i++)
    {
        avr += temp[i];
    }
    avr /= n;
    return avr * 10;
}
// Функция возвращает годовую статистику
void Year_Stat(sensor *Sensor_Data, int Num_Records)
{
    int i;
    int Temp_Year_Records[Num_Records];
    if (Num_Records == -1)
    {
        printf("\n"); // ошибка чтения файла
    }
    if (Num_Records == 0) // проверка на наличие записей
    {
        printf("IN THIS YEAR NO RECORDS!\n");
    }
    if (Num_Records > 0) // если записи есть, то создается массив из температур
    {
        for (i = 0; i < Num_Records; i++)
        {
            Temp_Year_Records[i] = Sensor_Data[i].t;
        }
        int max = Max_Temp(Temp_Year_Records, Num_Records);
        int min = Min_Temp(Temp_Year_Records, Num_Records);
        int avr = Avr_Temp(Temp_Year_Records, Num_Records);
        printf("------------------------------------------\n");
        printf("IN YEAR\n");
        printf("T_MAX: %d;\n", max);
        printf("T_MIN: %d;\n", min);
        printf("T_AVR: %.2f;\n", avr / 10.0);
        printf("------------------------------------------\n");
    }
}
// Функция возвращает колиечтсво записей в конкретном месяце
int Count_Month(sensor *Sensor_Data, int Num_Records, int Month)
{
    int i;
    int counter = 0;
    for (i = 0; i < Num_Records; i++)
        if ((Sensor_Data[i].month == Month))
            counter++;
    return counter;
}
// Функция вывода статистики помесячнов выбранном годе
void Month_Stat(sensor *Sensor_Data, int Num_Records)
{
    if (Num_Records == 0 || Num_Records == -1)
    {
        printf("\n"); // если записей нет, то об этом будет сказано в Year_Stat, а здесь будет просто переход строки
    }
    else
    {
        int Month_Number;
        for (Month_Number = 1; Month_Number < 13; Month_Number++) // пробегаемся по каждому месяцу
        {
            int Month_Records = Count_Month(Sensor_Data, Num_Records, Month_Number);
            int Month_Temp[Month_Records]; // создается массив температур в конкретном месяце длиной, равной количеству записей в данном месяце
            int i, j;
            j = 0;
            if (Month_Records == 0) // проверка на наличие записей в конкретном месяце
            {
                printf("NO STATISTIC IN %02d MONTH;\n", Month_Number);
                printf("------------------------------------------\n");
            }
            else
            {
                for (i = 0; i < Num_Records; i++)
                {
                    if ((Sensor_Data[i].month == Month_Number)) // запись темпаратуры в конкретном месяце
                    {
                        Month_Temp[j] = Sensor_Data[i].t;
                        j++;
                    }
                }
                int max = Max_Temp(Month_Temp, Month_Records);
                int min = Min_Temp(Month_Temp, Month_Records);
                int avr = Avr_Temp(Month_Temp, Month_Records);
                printf("STATISTIC IN %02d MONTH;\n", Month_Number);
                printf("MAXIMUM: %d;\n", max);
                printf("MINIMUM: %d;\n", min);
                printf("AVERAGE: %.2f;\n", avr / 10.0);
                printf("------------------------------------------\n");
            }
        }
    }
}
// Функция вывода статистики в конкретный месяц и год
void One_Month_Stat(sensor *Sensor_Data, int Num_Records, int Month)
{
    if (Num_Records == -1 || Num_Records == 0)
    {
        printf("\n");
    }
    else
    {
        if ((Month <= 0) || (Month > 12)) // проверка на корректный ввод месяца
        {
            printf("ERROR INPUT DATA (MONTH < 1 OR MONTH > 12)\n");
            printf("------------------------------------------\n");
        }
        else
        {
            int Length;
            Length = Count_Month(Sensor_Data, Num_Records, Month);
            if (Length == 0) // проверка на наличие записей в данном месяце
            {
                printf("IN %d NO RECORDS!\n", Month);
                printf("------------------------------------------\n");
            }
            else
            {
                int Month_Temp[Length]; // создаем массив температур длиной, равной количеству записей в данном месяце
                int i, j;
                j = 0;
                {
                    for (i = 0; i < Num_Records; i++)
                    {
                        if ((Sensor_Data[i].month == Month))
                        {
                            Month_Temp[j] = Sensor_Data[i].t; // запись значений температур
                            j++;
                        }
                    }
                    int max = Max_Temp(Month_Temp, Length);
                    int min = Min_Temp(Month_Temp, Length);
                    int avr = Avr_Temp(Month_Temp, Length);
                    printf("STATISTIC IN %02d;\n", Month);
                    printf("T_MAX: %d;\n", max);
                    printf("T_MIN: %d;\n", min);
                    printf("T_AVR: %.2f;\n", avr / 10.0);
                    printf("------------------------------------------\n");
                }
            }
        }
    }
}