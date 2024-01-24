#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    FILE *input = fopen("d1.txt", "r");
    char line[255];
    uint16_t last = 0;
    uint32_t increases = 0;

    while (fgets(line, 255, input) != NULL)
    {
        uint16_t current = atoi(line);
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
    printf("Total Increases: %d\n", increases);

    return 0;
}