#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */


void print (void *ptr);

typedef struct mess_data
{
    int times;
    char message[100];
}thdata;

int main (int argc, char *argv[])
{
    int true = 1;
    int num = 0;
    int i;
    int wordCount = 1;
    int numCount = 1;
    int intConv = 0;
    int NUM_THREADS = argc;
    int intNums[250];
    char *words[250];
    char *nums[250];
    struct mess_data thdata[100];

// This while loop takes the input of the user,
// puts team names in an array (words), puts the number
// of times said in a diff array (nums), then converts
// nums to an array of ints to be used later (intNums)
    while (true)
    {
            for (i = 1; i < argc; i++)
            {
                if (argv != '\0')
                {
                    if (i % 2 != 0)
                    {
                        words[wordCount] = argv[i];
                        printf("%s\n", words[wordCount]);
                        wordCount++;
                    }
                    else if (i%2 == 0)
                    {
                        nums[numCount] = argv[i];
                        printf("%s\n", nums[numCount]);
                        numCount++;
                    }
                }
            }
    true = 0;
    }

    for (i = 1; i < wordCount; i ++)
    {
        printf("%s %d\n", words[i], i);

    }
    for (i = 1; i < numCount; i ++)
    {
        printf("%s %d\n", nums[i], i);
        intConv = atoi(nums[i]);
        printf("Converted: %d\n", intConv);
        intNums[i] = intConv;
    }

     printf("Converted array\n");
    for (i = 1; i < numCount; i++)
    {
        printf("%d , ", intNums[i]);
    }

//// Creating the actual threads

    int count;
    int numThreads = NUM_THREADS/2;
    pthread_t thread_id[numThreads];
    for (count = 1; count <= numThreads; count++)
    {
        thdata[count].times = intNums[count];
        strcpy(thdata[count].message, words[count]);
    }

    for (count = 1; count <= numThreads; count ++)
    {
        printf("Thread created: %d\n", count);
        pthread_create (&thread_id[count],NULL, (void*) &print, (void*) &thdata[count]);

  sleep(1);
    }
    exit(0);


    return 0;

}

void print( void* ptr)
{
    int i;
    thdata *data;
    data = (thdata*) ptr; // type cast to a pointer
    for (i =0; i < data->times; i++)
    {
        printf("Go %s!, times: %d\n", data->message, data->times);

    }
    pthread_exit(0);
}
