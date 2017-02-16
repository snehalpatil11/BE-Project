// Title : fork() function

#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int
glob = 7;
int
main(void)
{
int var;
pid_t pid;
/* external variable in initialized data */
/* automatic variable on the stack */
var = 88;
printf("before vfork\n"); /* we don't flush stdio */
if ((pid = vfork()) < 0) 
{
printf("vfork error");

} else if (pid == 0)
 {
/* child */
glob++;
/* modify parent's variables */
var++;

_exit(0);
/* child terminates */
}
/*
* Parent continues here.
*/
printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
exit(0);
}

/*
student@student-HCL-Desktop:~$ gcc vfork.c
student@student-HCL-Desktop:~$ ./a.out
before vfork
pid = 2659, glob = 7, var = 89
*/


