#include <stdio.h>
#include <stdlib.h>
#include "qol.h"

int main()
{

    FILE *input = fopen("d1.txt", "r");
    char line[255];
    uint16 lasts[3] = {0, 0, 0};
    uint32 increases = 0;

    while (fgets(line, 255, input) != NULL)
    {
        uint16 current = atoi(line);

        // lasts[1] and lasts[2] are on both part of the comparaison and cancels eachother
        if (lasts[0] > 0 && current > lasts[0])
        {
            increases++;
        }
        // shift
        lasts[0] = lasts[1];
        lasts[1] = lasts[2];
        lasts[2] = current;
    }

    fclose(input);
    println("Total increases: %d", increases);

    return 0;
}