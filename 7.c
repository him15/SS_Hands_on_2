/*
Name:- HIMANSHU SHIVHARE
Roll No:- MT2024058
Program:-7. Write a simple program to print the created thread ids.
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void print()
{
    printf("Printing from thread :%lu\n", pthread_self());
}

void main()
{
    pthread_t threadID;
    int pstatus;

   for(int i=0;i<3;i++){
	threadID=i+1;
	pstatus = pthread_create(&threadID, NULL, (void *)print, NULL);
   	 if (pstatus != 0)
   	 {
        	perror("Error while creating thread");
        	_exit(1);
    	 }
	
   }
    pthread_exit(NULL);
}

/*
OUTPUT - 

himanshu@himanshu-Inspiron-15-3567:~/Desktop/Hanson2$ ./a.out
Printing from thread :139971308549824
Printing from thread :139971300157120
Printing from thread :139971291764416
*/
