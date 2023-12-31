#ifndef QOL_H
#define QOL_H

typedef char string[];
typedef unsigned char uint8;
typedef signed char int8;
typedef unsigned short uint16;
typedef signed short int16;
typedef unsigned long uint32;
typedef signed long int32;
typedef unsigned long long uint64;
typedef signed long long int64;

#define println(format, ...) printf(format "\n", ##__VA_ARGS__)

#endif
