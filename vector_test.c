#include <stdio.h>
#include "lib/vector.c"
#include <stdint.h>

int main()
{
    printf("Program Start\n");
    printf("Create Vector\n");
    Vector *myVector = Vector_new(sizeof(uint16_t));
    printf("Populate Vector\n");
    Vector_push(myVector, &(uint16_t){18});
    Vector_push(myVector, &(uint16_t){19});
    Vector_insert(myVector, &(uint16_t){20}, 1);
    printf("Check Vector\n");
    printf("First value is: %d\n", *(uint16_t *)Vector_get(myVector, 0));
    printf("Second value is: %d\n", *(uint16_t *)Vector_get(myVector, 1));
    printf("Third value is: %d\n", *(uint16_t *)Vector_get(myVector, 2));
    printf("The length of the vector is: %d\n", Vector_length(myVector));
    printf("Remove value\n");
    Vector_remove(myVector, 0);
    printf("First value is: %d\n", *(uint16_t *)Vector_get(myVector, 0));
    printf("Second value is: %d\n", *(uint16_t *)Vector_get(myVector, 1));
    printf("The length of the vector is: %d\n", Vector_length(myVector));
    Vector_free(myVector);
    printf("Program End\n");
    return 0;
}