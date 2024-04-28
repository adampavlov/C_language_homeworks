#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "temp_functions.h"

// Читает аргументы командной строки.
static void read_argv(int argc, char *argv[], int *year, int *month)
{
    int rez;
    // Обходим все аргументы командной строки
    while ((rez = getopt(argc, argv, "hHy::m::")) != -1)
    {
        switch (rez)
        {
        case 'h':
        case 'H':
            printf("        <HELPER MODE>\n THIS PROGRAMM PRINT STATISTIC OF TEMPERATURE.\n USE KEYS:\n");
            printf("1) -h or -H - FOR HELPER;\n");
            printf("2) -y<YEAR> (-y:)- ENTER THE YEAR FOR GET STATISTIC ONLY <MONTH NUMBER>;\n");
            printf("3) -m<MONTH NUMBER> (-m:)- ENTER MONTH NUMBER FOR GET STATISTIC ONLY <MONTH NUMBER>;\n");
            break;
        case 'y':
            if (optarg != NULL && optarg[0] != '-')
            {
                *year = atoi(optarg);
            }
            break;
        case 'm':
            if (optarg != NULL && optarg[0] != '-')
            {
                *month = atoi(optarg);
            }
            break;
        case '?':
            fprintf(stderr, "ERROR: UNKNOWN ARGUMENTS!\n");
            exit(1);
        }
    }
}

int main(int argc, char *argv[])
{
    printf("------------------------------------------\n");
    sensor info[SIZE];          // создали массив с тип данных sensor
    int number = AddInfo(info); // получили количество сделанных записей
    SortByD(info, number);      // произвели сортировку данных по дате
    printf("------------------------------------------\n");
    printf("          START PROGRAMM                  \n");
    int Year = 0 , Month = 0;
    read_argv(argc, argv, &Year, &Month);
    //printf("%04d-%02d\n", Year, Month);
    if (Year != 0 && Month != 0)
    {
        printf("------------------------------------------\n");
        One_Month_Stat(info, number, Year, Month);
    }
    //printf("SORTED DATA BY DATE\n");
    // Print(info, number); // вывели на печать отсортированный массив данных с датчика
    Year = 0;
    printf("TO GET ALL STATISTIC BY YEAR, ENTER THE YEAR: ");
    scanf("%d", &Year);             // получили от пользователя год, за который интерсует его статистика
    Year_Stat(info, number, Year);  // вывели статистику за год
    Month_Stat(info, number, Year); // вывели статистику по всем месяцам в выбранном году
    return 0;
}