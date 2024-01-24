#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define SIZE 12

int main()
{
    FILE *input = fopen("d3.txt", "r");
    char line[255];
    uint16_t bits[SIZE] = {0};
    uint16_t total = 0;
    uint16_t gamma = 0;
    uint16_t epsilon = 0;
    uint32_t power = 0;

    while (fgets(line, 255, input) != NULL)
    {
        for (uint8_t i = 0; i < SIZE; i++)
        {
            if (line[i] == '1')
            {
                bits[i]++;
            }
        }
        total++;
    }

    const uint16_t halfTotal = total >> 1;
    for (uint8_t i = 0; i < SIZE; i++)
    {
        // printf("%d: %d\n", i, bits[i]);
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
    printf("Total: %d\n", total);
    printf("Gamma: %d\n", gamma);
    printf("Epsilon: %d\n", epsilon);
    printf("Power: %d\n", power);

    return 0;
}