/*
Name:- Padaliya Shivam
Roll No:- MT2024107
Program:- 4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

// using time stamp counter
unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc"
                         : "=A"(dst));
    return dst;
}

void main()
{
    long long int start, end;

    start = rdtsc();
    int iter = 1;
    while (iter <= 100)
    {
        getppid();
        iter += 1;
    }

    end = rdtsc();

    printf("time required : %llu\n", end - start);
}

/*
OUTPUT-

himanshu@himanshu-Inspiron-15-3567:~/Desktop/Hanson2$ ./a.out
time required : 704668

*/
