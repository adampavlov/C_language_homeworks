#include <stdio.h>
#include "temp_api.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 30

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


int main(void)
{
    sensor info[SIZE];
    int number = Add_Info(info);
    print(info, number);

    return 0;
}
