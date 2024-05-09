#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_api.h"

int main(int argc, char *argv[])
{
    printf("------------------------------------------\n");
    printf("START PROGRAMM!\n");
    printf("------------------------------------------\n");
    char filename[FILENAME_MAX_LENGTH] = {0};
    sensor *Sensor_Data = NULL;
    int Month = 0;

    Read_argv(argc, argv, filename, &Month);
    if (argc == 1)
    {
        printf("USE KEYS -h or -H - FOR HELPER\n");
    }
    else
    {
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
    }
    // filename = "temperature_small.csv";
    // filename = "temperature_big.csv";
    // filename = "empty.csv";
    return 0;
}
