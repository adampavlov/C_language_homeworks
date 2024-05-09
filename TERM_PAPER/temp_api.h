#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Максимальная длина имени файла.
#define FILENAME_MAX_LENGTH 255 

typedef struct
{
    /* создается структура sensor с полями год (dddd), месяц (dd), день (dd), часы (hh), минуты (hh) и температура (-99..+99) */
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t t;
} sensor; 
/* сделали тип sensor */

// Функция читает csv файл, записывает данные в структуру типа sensor и возвращает количество корректных сделанных записей в структуру
int Read_CSV(char *Filename, sensor **Sensor_Data);  
// Функция вывода максимальной температуры за год (весь период наблюдения)
int Max_Temp(int *temp, int n);
// Функция вывода минимальной температуры за год (весь период наблюдения)
int Min_Temp(int *temp, int n);
// Функция вывода среднегодовой температуры (средней за весь период наблюдения)
int Avr_Temp(int *temp, int n);
// Функция возвращает годовую статистику
void Year_Stat(sensor *Sensor_Data, int Num_Records);
// Функция возвращает колиечтсво записей в конкретном месяце
int Count_Month(sensor *Sensor_Data, int Num_Records, int Month);
// Функция вывода статистики помесячнов выбранном
void Month_Stat(sensor *Sensor_Data, int Num_Records);
// Читает аргументы командной строки.
void Read_argv(int argc, char *argv[], char *filename, int *month);