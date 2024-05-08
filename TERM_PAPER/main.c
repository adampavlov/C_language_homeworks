#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_api.h"

// Читает аргументы командной строки.
static void read_argv(int argc, char *argv[], char *filename, int *month)
{
    int rez;
    // Обходим все аргументы командной строки
    while ((rez = getopt(argc, argv, "hHf::m::")) != -1)
    {
        switch (rez)
        {
        case 'h':
        case 'H':
            printf("        <HELPER MODE>\n THIS PROGRAMM PRINT STATISTIC OF TEMPERATURE FROM DOWNLOAD FILE.\n USE KEYS:\n");
            printf("1) -h or -H - FOR HELPER;\n");
            printf("2) -f<FILENAME> (-f:)- ENTER THE FILENAME FOR READ DATA AND GET YEAR STATISTC;\n");
            printf("3) -m<MONTH NUMBER> (-m:)- ENTER THE MONTH NUMBER FOR GET STATISTIC ONLY;\n");
            printf("\n");
            printf("(EXAMPLE OF THERMINAL COMMAND: >>prog.exe -f<FILENAME.CSV> -m<MONTH NUMBER>)\n");
            printf("------------------------------------------\n");
            break;
        case 'f':
            if (optarg != NULL && optarg[0] != '-')
            {
                strncpy(filename, optarg, FILENAME_MAX_LENGTH);
            }
            else
            {
                fprintf(stderr, "ERROR: MISSING ARGUMENT FOR KEY -f\n");
                exit(1);
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
    printf("START PROGRAMM!\nUSE KEYS -h or -H - FOR HELPER\n");
    printf("------------------------------------------\n");
    char filename[FILENAME_MAX_LENGTH] = {0};
    sensor *Sensor_Data = NULL;
    int Month = 0;

    read_argv(argc, argv, filename, &Month);
    int Num_Records = Read_CSV(filename, &Sensor_Data);
    printf("------------------------------------------\n");
    if (Month == 0)
    {
        Year_Stat(Sensor_Data, Num_Records);
        Month_Stat(Sensor_Data, Num_Records);
    }
    else
    {
        One_Month_Stat(Sensor_Data, Num_Records, Month);
    }
    // filename = "temperature_small.csv";
    // filename = "temperature_big.csv";
    // filename = "empty.csv";
    return 0;
}
