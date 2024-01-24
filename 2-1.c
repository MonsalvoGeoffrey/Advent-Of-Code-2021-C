#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct Position
{
    uint32_t horizontal;
    uint32_t depth;
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
        uint16_t distance = atoi(strtok(NULL, " "));

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
        // printf("%s | %d | %d\n", direction, distance, submarine.depth);
    }

    fclose(input);
    printf("The horizontal distance is: %d\n", submarine.horizontal);
    printf("The depth distance is: %d\n", submarine.depth);
    printf("The horizontal and depth distance multiplied is: %d\n", submarine.horizontal * submarine.depth);

    return 0;
}