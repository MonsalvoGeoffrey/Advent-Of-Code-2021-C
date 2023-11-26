#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/qol.h"

typedef struct Position
{
    uint32 horizontal;
    uint32 depth;
} Position;

int main()
{
    FILE *input = fopen("d2.txt", "r");
    char line[255];
    Position submarine = {0, 0};

    while (fgets(line, 255, input) != NULL)
    {
        char direction[255];
        char *pDirection = strtok(line, " ");
        strcpy(direction, pDirection);
        uint16 distance = atoi(strtok(NULL, " "));

        // printf(direction);
        if (strcmp(direction, "forward") == 0)
        {
            submarine.horizontal += distance;
        }
        else if (strcmp(direction, "up") == 0)
        {
            submarine.depth -= distance;
        }
        else if (strcmp(direction, "down") == 0)
        {
            submarine.depth += distance;
        }
        // println("%s | %d | %d", direction, distance, submarine.depth);
    }

    fclose(input);
    println("The horizontal distance is: %d", submarine.horizontal);
    println("The depth distance is: %d", submarine.depth);
    println("The horizontal and depth distance multiplied is: %d", submarine.horizontal * submarine.depth);

    return 0;
}