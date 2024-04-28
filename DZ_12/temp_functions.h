/* Защитный интервал:
    Если макрос TEMP_FUNCTIONS_H ранее не был объявлен, то код внутри конструкции
        #ifndef TEMP_FUNCTIONS_H
        #endif
    будет выполнен.
*/

#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdint.h>
#include "main.h"

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    int8_t t;
} sensor;

// Функция записи данных в массив: в поля массива записываются соотвествующие данные
static void AddRecord(sensor *info, int number, uint16_t Y, uint8_t M, uint8_t D, int8_t T);
static ChangeIJ(sensor *info, int i, int j);
// функция добавления данных
int AddInfo(sensor *info);
// Функция печати массива
void Print(sensor *info, int number);
// Функция упорядочивания по температуре
void SortByT(sensor *info, int n);
// Функция упорядочивания по дате
void SortByD(sensor *info, int n);
// Функция возвращает максимальное значение массива
int Max_Temp(int *temp, int n);
// Функция возвращает минимальное значение массива
int Min_Temp(int *temp, int n);
//Функция вывода среднегодовой температуры (средней за весь период наблюдения)
int Avr_Temp(int *temp, int n);
// Функция считает количество записей в введенном годе
int Count_Year(sensor *info, int n, int Year);
// Функция возвращает колиечтсво записей в конкретном году в конкретном месяце
int Count_Month(sensor *info, int n, int Year, int Month);
// Функция выводит статистику за выбранный год
void Year_Stat(sensor *info, int n, int Year);
// Функция вывода статистики помесячнов выбранном годе
void Month_Stat(sensor *info, int n, int Year);
// Функция вывода статистики в конкретный месяц и год
void One_Month_Stat(sensor *info, int n, int Year, int Month);

#endif // защитный интервал