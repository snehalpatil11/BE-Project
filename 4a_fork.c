// Title : fork() function  

#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
//#include<fcntl.h>

int glob = 6;

/* external variable in initialized data */
char buf[] = "a write to stdout\n";
int
main(void)
{
int var;
pid_t pid;		
		/* automatic variable on the stack */
var = 80;
if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
printf("write error");
printf("before fork\n");                    /* we don't flush stdout */

if ((pid = fork()) < 0) 
{
printf("fork error");
} 
  
else if (pid == 0)                 /* child */
 {

glob++;				/* modify variables */
var++;
}
 else {
sleep(2);
				/* parent */
}


printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
exit(0);
}


/*
student@student-HCL-Desktop:~$ gcc fork.c
student@student-HCL-Desktop:~$ ./a.out
a write to stdout
before fork
pid = 2905, glob = 7, var = 81
pid = 2904, glob = 6, var = 80


student@student-HCL-Desktop:~$ ./a.out>temp.out
student@student-HCL-Desktop:~$ cat temp.out
a write to stdout
before fork
pid = 2690, glob = 7, var = 89
before fork
pid = 2689, glob = 6, var = 88

*/
