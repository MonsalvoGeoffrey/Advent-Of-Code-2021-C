#include <stdio.h>
#include "lib/vector.c"

int main()
{
    printf("Program Start\n");
    printf("Create Vector\n");
    Vector *myVector = Vector_new(sizeof(uint16));
    printf("Populate Vector\n");
    Vector_push(myVector, &(uint16){18});
    Vector_push(myVector, &(uint16){19});
    Vector_insert(myVector, &(uint16){20}, 1);
    printf("Check Vector\n");
    printf("First value is: %d\n", *(uint16 *)Vector_get(myVector, 0));
    printf("Second value is: %d\n", *(uint16 *)Vector_get(myVector, 1));
    printf("Third value is: %d\n", *(uint16 *)Vector_get(myVector, 2));
    printf("The length of the vector is: %d\n", Vector_length(myVector));
    printf("Remove value\n");
    Vector_remove(myVector, 0);
    printf("First value is: %d\n", *(uint16 *)Vector_get(myVector, 0));
    printf("Second value is: %d\n", *(uint16 *)Vector_get(myVector, 1));
    printf("The length of the vector is: %d\n", Vector_length(myVector));
    Vector_free(myVector);
    printf("Program End\n");
    return 0;
}