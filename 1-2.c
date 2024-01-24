#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{

    FILE *input = fopen("d1.txt", "r");
    char line[255];
    uint16_t lasts[3] = {0, 0, 0};
    uint32_t increases = 0;

    while (fgets(line, 255, input) != NULL)
    {
        uint16_t current = atoi(line);

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
    printf("Total increases: %d\f", increases);

    return 0;
}