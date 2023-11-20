## I'm using Advent of Code 2021 as exercices to learn and practice programming in C

In Advent of Code, each day contain two puzzles, the second one being a harder version of the first one, for a total of 50 puzzles of increasing difficulty.

In this repository, I'll list all of my working code in the format `X-Y.c`, with X being the day and Y being which of the day's challenge it's corresponding to. And `X-Y.txt` being the input.

## What I've learned through this challenge.

Day 1, Challenge 1:
- Opening and reading a file
- atoi() for string to int converstion

Day 1, Challenge 2:
- Importing custom header files (Using it for `qol.h`, a set of typedef and macros that make C more comfortable for me)

At this point I decided to write a Makefile to compile/cleanup everything at once.
`make` will compile everything
`make clean` will delete every .exe file
It's unnecessary, but I learned how Makefile works recently so that's good practice.