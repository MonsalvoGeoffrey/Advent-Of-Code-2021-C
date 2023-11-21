## I'm using Advent of Code 2021 as exercices to learn and practice programming in C

In Advent of Code, each day contain two puzzles, the second one being a harder version of the first one, for a total of 50 puzzles of increasing difficulty.

In this repository, I'll list all of my working code in the format `X-Y.c`, with X being the day and Y being which of the day's challenge it's corresponding to. And `X-Y.txt` being the input.

## What I've learned through this challenge.

### Day 1, Challenge 1:
- Opening and reading a file
- atoi() for string to int converstion

### Day 1, Challenge 2:
- Importing custom header files (Using it for `qol.h`, a set of typedef and macros that make C more comfortable for me)

At this point I decided to write a Makefile to compile/cleanup everything at once.
`make` will compile everything
`make clean` will delete every .exe file
It's unnecessary, but I learned how Makefile works recently so that's good practice.

### Day 2, Challenge 1:
- Dealing with strings is horrible !!!
- strcmp for string comparaison __(return 0 if true)__
- strtok for string spliting (**/!\ DESTRUCTIVE**, returns a pointer)
- `typedef char string[];` isn't that helpful to deal with strings, C has an obsession with having to know the length in advance
- Riiiight, switch don't work on strings
- strcpy is necessary to extract the value of a pointer to a string (Since strings are just array of characters, the pointer actually only points to the first character, the function strcpy probably loop over the pointer and the next elements until it find a null byte)

### Day 3, Challenge 1:
- How to do exponents
- Think of using the example as a test case
- `int myVar[MY_CONST] = {0};` can be used to have an array of size that depends on a constant (macro) value
