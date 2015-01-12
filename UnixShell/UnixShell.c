/*
OS Program 1
Creating a Unix Shell

Jennifer Jozefiak
September 24, 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>



int main(int argc, char *argv[])
{
    // Creates base for file to write the input to
    char a[100];
    FILE *file;
    int true = 1;
    char BUFF[1024];
    int result;
    file = fopen("input.txt","w");
    printf("\nEnter input %% ");
    result = scanf("%s", a);

    // Scans the input, making sure it is viable. If so, create the fork.
    // In the child, run the command if it is viable.
    // Basic error checking to ensure proper functioning

    while(result != EOF)
    {
        printf("You entered: %s\n", a);

        fprintf(file, "%s\n", a);
        fflush(file);
        pid_t child = fork();

        if (child < 0)
        {
            perror("fork failed");
        }
        else if(child > 0)
        {
            while((child = wait(NULL)) != -1)
			{
				if(errno != ECHILD)
				{
					perror("wait error");
				}
			}
        }
        else if (child == 0)
        {
            char* args[] = {"-l",NULL};
            // execlp executes the command
            execlp(a,a,(char*)0);
            perror("Command Failed");
        }

        // Loops the beginning prompt to continue entering commands.
        printf("\nEnter input %% ");
        result = scanf("%s", a);


    }
    exit(0);

    return 0;
}
