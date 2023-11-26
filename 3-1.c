#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib/qol.h"

#define SIZE 12

int main()
{
    FILE *input = fopen("d3.txt", "r");
    char line[255];
    uint16 bits[SIZE] = {0};
    uint16 total = 0;
    uint16 gamma = 0;
    uint16 epsilon = 0;
    uint32 power = 0;

    while (fgets(line, 255, input) != NULL)
    {
        for (uint8 i = 0; i < SIZE; i++)
        {
            if (line[i] == '1')
            {
                bits[i]++;
            }
        }
        total++;
    }

    const uint16 halfTotal = total >> 1;
    for (uint8 i = 0; i < SIZE; i++)
    {
        // println("%d: %d", i, bits[i]);
        if (bits[i] > halfTotal)
        {
            gamma += pow(2, (SIZE - 1) - i);
            printf("1");
        }
        else
        {
            epsilon += pow(2, (SIZE - 1) - i);
            printf("0");
        }
    }
    printf("\n");
    power = gamma * epsilon;
    println("Total: %d", total);
    println("Gamma: %d", gamma);
    println("Epsilon: %d", epsilon);
    println("Power: %d", power);

    return 0;
}