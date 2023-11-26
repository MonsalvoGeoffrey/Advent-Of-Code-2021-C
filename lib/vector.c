#include <stdlib.h>
#include <string.h>
#include "qol.h"

typedef struct Vector
{
    uint32 size;
    uint32 actualSize;
    uint16 elementSize;
    void *data;
} Vector;

Vector *Vector_new(uint16 elementSize)
{
    Vector *vector = malloc(sizeof(Vector));
    vector->size = 0;
    vector->actualSize = 8;
    vector->elementSize = elementSize;
    vector->data = malloc(elementSize * vector->actualSize);
    for (uint32 i = 0; i < vector->actualSize * vector->elementSize; i++)
    {
        ((char *)vector->data)[i] = 0;
    }
    return vector;
};

void Vector_free(Vector *vector)
{
    free(vector->data);
    vector->size = 0;
    vector->actualSize = 0;
    vector->elementSize = 0;
    free(vector);
}

void Vector_resize(Vector *vector, uint16 newSize)
{
    vector->actualSize = newSize;
    void *newData = realloc(vector->data, vector->elementSize * vector->actualSize);
    if (newData)
    {
        vector->data = newData;
    }
    else
    {
        fprintf(stderr, "Error: Something's wrong, this message isn't helpful.");
    }
}

void Vector_push(Vector *vector, void *element)
{
    vector->size++;
    if (vector->size > vector->actualSize)
    {
        Vector_resize(vector, vector->actualSize * 2);
    }
    void *destination = (char *)vector->data + ((vector->size - 1) * vector->elementSize);
    memcpy(destination, element, vector->elementSize);
}

void *Vector_get(Vector *vector, uint32 index)
{
    if (index >= vector->size)
    {
        fprintf(stderr, "Error: Index out of bounds.\n");
        return NULL;
    }

    char *element = (char *)vector->data + (index * vector->elementSize);
    return (void *)element;
}

void Vector_insert(Vector *vector, void *element, uint32 index)
{
    vector->size++;
    if (vector->size > vector->actualSize)
    {
        Vector_resize(vector, vector->actualSize * 2);
    }
    if (index >= vector->size)
    {
        fprintf(stderr, "Error: Index out of bounds.\n");
    }
    void *destination = (char *)vector->data + (index * vector->elementSize);
    memcpy((char *)destination + vector->elementSize, destination, (vector->size - index) * vector->elementSize);
    memcpy(destination, element, vector->elementSize);
}

void Vector_remove(Vector *vector, uint32 index)
{
    if (index >= vector->size)
    {
        fprintf(stderr, "Error: Index out of bounds.\n");
    }
    vector->size--;
    void *destination = (char *)vector->data + (index * vector->elementSize);
    memcpy(destination, (char *)destination + vector->elementSize, (vector->size - index + 1) * vector->elementSize);
}

uint32 Vector_length(Vector *vector)
{
    return vector->size;
}
