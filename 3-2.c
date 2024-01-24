#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib/vector.c"
#include <stdint.h>

#define SIZE 12

int main()
{
    FILE *input = fopen("d3.txt", "r");
    char line[255];
    uint16_t oxygen = 0;
    uint16_t co2 = 0;
    Vector *oxygenList = Vector_new(sizeof(char[SIZE + 1]));
    Vector *co2List = Vector_new(sizeof(char[SIZE + 1]));
    uint32_t life = 0;

    while (fgets(line, 255, input) != NULL)
    {
        char value[SIZE + 1];
        strncpy(value, line, SIZE + 1);
        value[SIZE] = '\0';
        Vector_push(oxygenList, value);
        Vector_push(co2List, value);
    }

    uint8_t cursor = 0;
    while (Vector_length(oxygenList) > 1)
    {
        uint16_t halfCount = Vector_length(oxygenList);
        halfCount = (halfCount >> 1) + (halfCount % 2);
        uint16_t oneCount = 0;
        for (int16_t i = Vector_length(oxygenList) - 1; i >= 0; i--)
        {
            if (((char *)Vector_get(oxygenList, i))[cursor] == '1')
            {
                oneCount++;
            }
        }
        char charToKeep = '0';
        if (oneCount >= halfCount)
        {
            charToKeep = '1';
        }
        for (int16_t i = Vector_length(oxygenList) - 1; i >= 0; i--)
        {
            if (((char *)Vector_get(oxygenList, i))[cursor] != charToKeep)
            {
                Vector_remove(oxygenList, i); // Safe due itterating the loop backward
            }
        }
        cursor++;
    }

    cursor = 0;
    while (Vector_length(co2List) > 1)
    {
        uint16_t halfCount = Vector_length(co2List);
        halfCount = (halfCount >> 1) + (halfCount % 2);
        uint16_t oneCount = 0;
        for (int16_t i = Vector_length(co2List) - 1; i >= 0; i--)
        {
            if (((char *)Vector_get(co2List, i))[cursor] == '1')
            {
                oneCount++;
            }
        }
        char charToKeep = '0';
        if (oneCount < halfCount)
        {
            charToKeep = '1';
        }
        for (int16_t i = Vector_length(co2List) - 1; i >= 0; i--)
        {
            if (((char *)Vector_get(co2List, i))[cursor] != charToKeep)
            {
                Vector_remove(co2List, i); // Safe due itterating the loop backward
            }
        }
        cursor++;
    }

    char *endptr;

    oxygen = strtol((char *)Vector_get(oxygenList, 0), &endptr, 2);
    co2 = strtol((char *)Vector_get(co2List, 0), &endptr, 2);
    life = oxygen * co2;

    printf("Oxygen: %d\n", oxygen);
    printf("Co2: %d\n", co2);
    printf("Life Support: %d\n", life);

    Vector_free(oxygenList);
    Vector_free(co2List);

    return 0;
}