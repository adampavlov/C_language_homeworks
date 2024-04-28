#include "temp_functions.h"
#include <stdio.h>

// Функция записи данных в массив: в поля массива записываются соотвествующие данные
// Имена переменных не должны совпадать с именами полей структуры sensor
static void AddRecord(sensor *info, int number, uint16_t year, uint8_t month, uint8_t day, int8_t t)
{
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].t = t;
}

// функция добавления данных и вывода номера записи
int AddInfo(sensor *info)
{
    int counter = 0;
    AddRecord(info, counter++, 2021, 1, 1, -25);
    AddRecord(info, counter++, 2021, 1, 15, -19);
    AddRecord(info, counter++, 2021, 1, 30, -10);
    AddRecord(info, counter++, 2021, 2, 16, -19);
    AddRecord(info, counter++, 2021, 2, 1, -15);
    AddRecord(info, counter++, 2021, 3, 1, -11);
    AddRecord(info, counter++, 2021, 3, 16, -7);
    AddRecord(info, counter++, 2021, 3, 20, -1);
    AddRecord(info, counter++, 2021, 3, 30, 0);
    AddRecord(info, counter++, 2021, 4, 1, 0);
    AddRecord(info, counter++, 2021, 4, 16, 1);
    AddRecord(info, counter++, 2021, 4, 30, 5);
    AddRecord(info, counter++, 2021, 6, 1, 19);
    AddRecord(info, counter++, 2021, 6, 15, 18);
    AddRecord(info, counter++, 2021, 6, 29, 22);
    AddRecord(info, counter++, 2021, 7, 1, 16);
    AddRecord(info, counter++, 2021, 7, 14, 22);
    AddRecord(info, counter++, 2021, 7, 30, 24);
    AddRecord(info, counter++, 2021, 8, 2, 16);
    AddRecord(info, counter++, 2021, 8, 18, 19);
    AddRecord(info, counter++, 2021, 8, 27, 26);
    AddRecord(info, counter++, 2021, 9, 1, 10);
    AddRecord(info, counter++, 2021, 9, 17, 14);
    AddRecord(info, counter++, 2021, 9, 30, 7);
    AddRecord(info, counter++, 2021, 10, 1, 5);
    AddRecord(info, counter++, 2021, 10, 15, 0);
    AddRecord(info, counter++, 2021, 10, 28, 3);
    AddRecord(info, counter++, 2021, 11, 16, -9);
    AddRecord(info, counter++, 2021, 11, 1, -3);
    AddRecord(info, counter++, 2021, 11, 30, -5);
    AddRecord(info, counter++, 2021 , 11 , 31 , -5 );
    AddRecord(info, counter++, 2021 , 12, 3, -7);
    AddRecord(info, counter++, 2021, 12, 16, -9);
    AddRecord(info, counter++, 2021, 12, 30, -15);
    AddRecord(info, counter++, 2021, 7, 25, 22);
    AddRecord(info, counter++, 2022, 5, 15, 12);
    AddRecord(info, counter++, 2022, 7, 30, 20);
    AddRecord(info, counter++, 2022, 3, 16, -10);
    AddRecord(info, counter++, 2022, 1, 1, -15);
    AddRecord(info, counter++, 2021, 2, 25, -17);
    AddRecord(info, counter++, 2022, 9, 15, 7);
    return counter;
}

// Функция печати массива
void Print(sensor *info, int number)
{
    printf("------------------------------------------\n");
    printf("|Year |Month|Day |Temperature|\n");
    int i;
    for (i = 0; i < number; i++)
    {
        printf("|%04d |%02d   |%02d  |%02d\n",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].t);
    }
    printf("------------------------------------------\n");
}

static ChangeIJ(sensor *info, int i, int j)
{
    sensor temp;
    temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}

// функция упорядочивания по температуре
void SortByT(sensor *info, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            if (info[i].t >= info[j].t)
                ChangeIJ(info, i, j);
}
// Функция преобразования байтов даты в одно число
unsigned int DateToInt(sensor *info)
{
    return info->year << 16 | info->month << 8 | info->day;
    // return (*info).year << 16 | (*info).month << 8 | (*info).day;
}
// функция упорядочивания по дате
void SortByD(sensor *info, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            if (DateToInt(info + i) >= DateToInt(info + j))
                ChangeIJ(info, i, j);
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

// Функция считает количество записей в введенном годе
int Count_Year(sensor *info, int n, int Year)
{
    int i;
    int counter = 0;
    for (i = 0; i < n; i++)
        if (info[i].year == Year)
            counter++;
    return counter;
}

// Функция возвращает статистику за выбранный год
void Year_Stat(sensor *info, int n, int Year)
{
    int i, j, length;
    j = 0;
    length = Count_Year(info, n, Year);
    int Temp_Year_Records[length];
    if (length == 0)
    {
        printf("IN %d YEAR NO RECORDS!\n", Year);
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (info[i].year == Year)
            {
                Temp_Year_Records[j] = info[i].t;
                j++;
            }
        }
        int max = Max_Temp(Temp_Year_Records, length);
        int min = Min_Temp(Temp_Year_Records, length);
        int avr = Avr_Temp(Temp_Year_Records, length);
        printf("------------------------------------------\n");
        printf("Maximum: %d;\n", max);
        printf("Minimum: %d;\n", min);
        printf("Average: %f;\n", avr / 10.0);
        printf("------------------------------------------\n");
    }
}

// Функция возвращает колиечтсво записей в конкретном году в конкретном месяце
int Count_Month(sensor *info, int n, int Year, int Month)
{
    int i;
    int counter = 0;
    for (i = 0; i < n; i++)
        if ((info[i].year == Year) && (info[i].month == Month))
            counter++;
    return counter;
}

// Функция вывода статистики помесячнов выбранном годе
void Month_Stat(sensor *info, int n, int Year)
{
    int length;
    length = Count_Year(info, n, Year);
    if (length == 0)
    {
        printf("\n");
    }
    else
    {
        int month_number;
        for (month_number = 1; month_number < 13; month_number++)
        {
            int month_records = Count_Month(info, n, Year, month_number);
            int month_temp[month_records];
            int i, j;
            j = 0;
            if (month_records == 0)
            {
                printf("NO STATISTIC IN %02d MONTH;\n", month_number);
                printf("------------------------------------------\n");
            }
            else
            {
                for (i = 0; i < n; i++)
                {
                    if ((info[i].year == Year) && (info[i].month == month_number))
                    {
                        month_temp[j] = info[i].t;
                        j++;
                    }
                }
                int max = Max_Temp(month_temp, month_records);
                int min = Min_Temp(month_temp, month_records);
                int avr = Avr_Temp(month_temp, month_records);
                printf("STATISTIC IN %02d MONTH;\n", month_number);
                printf("MAXIMUM: %d;\n", max);
                printf("MINIMUM: %d;\n", min);
                printf("AVERAGE: %f;\n", avr / 10.0);
                printf("------------------------------------------\n");
            }
        }
    }
}

// Функция вывода статистики в конкретный месяц и год
void One_Month_Stat(sensor *info, int n, int Year, int Month)
{
    if ((Month < 1) || (Month > 12))
    {
        printf("ERROR INPUT DATA (MONTH < 1 OR MONTH > 12)\n");
        printf("------------------------------------------\n");
    }
    else
    {
        int length;
        length = Count_Month(info, n, Year, Month);
        if (length == 0)
        {
            printf("IN %d-%d NO RECORDS!\n", Year, Month);
            printf("------------------------------------------\n");
        }
        else
        {
            int month_temp[length];
            int i, j;
            j = 0;
            {
                for (i = 0; i < n; i++)
                {
                    if ((info[i].year == Year) && (info[i].month == Month))
                    {
                        month_temp[j] = info[i].t;
                        j++;
                    }
                }
                int max = Max_Temp(month_temp, length);
                int min = Min_Temp(month_temp, length);
                int avr = Avr_Temp(month_temp, length);
                printf("STATISTIC IN %04d-%02d;\n", Year, Month);
                printf("MAXIMUM: %d;\n", max);
                printf("MINIMUM: %d;\n", min);
                printf("AVERAGE: %f;\n", avr / 10.0);
                printf("------------------------------------------\n");
            }
        }
    }
}