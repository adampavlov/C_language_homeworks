#include <stdint.h>

typedef struct 
{
/* создается структура sensor с полями год (dddd), месяц (dd), день (dd), часы (hh), минуты (hh) и температура (-99..+99) */
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t t;
} sensor;/* сделали тип sensor */

void Add_Record(sensor * info, int number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t)
/*на вход поступает укзатель на массив, номер элемента массива и поля структуры*/
{
    info[number].year = year;
    //(info+number) -> year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minute = minute;
    info[number].t = t;
/*в поля записываем соответствующие значения*/
}

int Add_Info(sensor * info)
/*на вход поступает укзатель на массив*/
{
    int counter = 0;
    Add_Record(info, counter++, 2021, 9, 16, 16, 35, 9);
    Add_Record(info, counter++, 2022, 9, 2, 10, 19, -9);
    Add_Record(info, counter++, 2021, 1, 7,23, 59, 8);
    Add_Record(info, counter++, 2021, 9, 5,18, 9, 1);
    return counter;
/*элементы массива info заполняются структурой типа sensor через вызов функции Add_Record, которая записывает значения в поля структуры*/
}

void print(sensor * info, int number)
{
    printf("======================================================\n");
    int i;
    for (i = 0; i < number; i++)
    {
        printf("Data %04d.%02d.%02d | Time %02d : %02d | Temperature %3d \n", info[i].year, info[i].month, info[i].day, info[i].hour, info[i].minute, info[i].t);
    }
    printf("======================================================\n");
}

