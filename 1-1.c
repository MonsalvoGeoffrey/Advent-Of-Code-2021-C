#include <stdio.h>
#include <stdlib.h>

typedef char string[];
typedef unsigned char uint8;
typedef signed char int8;
typedef unsigned short uint16;
typedef signed short int16;
typedef unsigned long uint32;
typedef signed long int32;
typedef unsigned long long uint64;
typedef signed long long int64;

#define println(format, ...) printf(format "\n", ##__VA_ARGS__)

int main()
{
    FILE *input = fopen("d1.txt", "r");
    char line[255];
    uint16 last = 0;
    uint32 increases = 0;

    while (fgets(line, 255, input) != NULL)
    {
        uint16 current = atoi(line);
        if (current > last)
        {
            increases++;
        }
        last = current;
    }

    if (increases > 0)
    {
        increases--;
    }
    fclose(input);
    println("Total Increases: %d", increases);

    return 0;
}