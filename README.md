# Project 2:  System Calls, Kernel Modules & Schedulers

# Developers:  Edward Skrod, Todd Ryks

# Date:  October 2, 2014

# Summary
1. Part 1:  
	Part 1 is a C program that uses exactly 20 more system calls than are used in an empty program. On the MCH202 lab computers, an empty C program has exactly 26 system calls. Our program, tracetest, produces 46 system calls.

2. Part 2:
    Part 2 is a kernel module that creates a virtual file with the current date. This virtual file is called currentdate. It always contains the current time in the format year-month-day hour:minute:second.

# Compilation
# Part 1
1. cd src
2. gcc -o tracetest tracetest.c
3. sudo strace -o log ./tracetest

# Part 2
1. cd src
2. make
3. sudo insmod date.ko
4. cat /proc/currentdate

# Files
# Part 1
1. tracetest.c
	Source Code
2. tracetest
	Executable
3. log
	Log file that was the result of running strace -o log ./tracetest

# Part 2
1. date.c
    Source Code
2. Makefile
    Make file
