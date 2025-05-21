#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// for deep comments check nextThread C file 

void *printNum()
{
    int i;
    for (i = 1; i < 10; i++)
    {
        printf("Thread1 : %d \n", i);
        sleep(1);
    }
    return NULL;
}

int main()
{
    // It only creates the Thread 
    pthread_t t1;

    // pthread_create it's simply create the thread and run immediately
    // it's schedule by scheduler and put it into the queue 
    // 1st NULL means any setting about thread like (priority,stack Size)
    // 2nd NULL means any parameter to send to the Function
    int checkThread = pthread_create(&t1, NULL, printNum, NULL);

    // if checkThread = 0 means successfully running the thread
    if (checkThread != 0)
    {
        printf("Error in Creating Thread \n");
        return 1;
    }

    // This is the Main Thread By Process 
    int i;
    for (i = 1; i < 10; i++)
    {
        printf("Main Thread: %d \n", i);
        sleep(1);
    }

    // It means Until t1 not done there task till other threads must be pause
    pthread_join(t1, NULL);

    printf("Main Thread And Thread 1 Finished!");

    return 0;
}