all: sensor_stat

sensor_stat: main.o temp_functions.o
	gcc -o sensor_stat main.o temp_functions.o

main.o: main.c
	gcc -c -o main.o main.c

temp_functions.o: temp_functions.c
	gcc -c -o temp_functions.o temp_functions.c

clean:
	del *.o
	del sensor_stat.exe