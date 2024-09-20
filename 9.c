/*
Name:- HIMANSHU SHIVHARE
Roll No:- MT2024058
Program:-9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void main()
{
    __sighandler_t status;

    printf("ignoring the SIGINT signal for 6 seconds\n");
    status=signal(SIGINT, SIG_IGN);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(6); // SIGINT will be ingnored for 6 seconds
    }

    printf("reseting the default action of the SIGINT signal\n");
    status = signal(SIGINT, SIG_DFL);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(6); 
    }
}

/*
	OUTPUT-

himanshu@himanshu-Inspiron-15-3567:~/Desktop/Hanson2$ ./a.out
ignoring the SIGINT signal for 6 seconds
reseting the default action of the SIGINT signal


*/
