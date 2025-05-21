#include <stdio.h>   // For printf() to display output on screen
#include <pthread.h> // POSIX Threads library: functions to create/manage threads
#include <unistd.h>  // Provides sleep() function to pause execution
#include <stdlib.h>  // Standard library (not used heavily here, but generally useful)

/*

    Compilation flow summary (for your understanding):

    Your Code (my.c)
        ↓
    [Preprocessor] → Processes #include directives, expands headers into your code
        ↓
    [Compiler] → Converts expanded code into assembly instructions
        ↓
    [Assembler] → Converts assembly into machine code (.o file)
        ↓
    [Linker] → Links your code with system libraries like libc (printf) and libpthread (thread funcs)
        ↓
    Generates executable binary (myprog)

*/

struct myStruct
{
    int st;  // Start number of sequence for thread to print
    int end; // End number of sequence
};

// Thread function signature: must take void* and return void*
// This function will run concurrently in a separate thread
void *myFn(void *arg)
{
    // arg is passed as a generic pointer; cast back to actual struct type
    struct myStruct *myData = (struct myStruct *)arg;

    // Dereference struct to get start and end values
    int start = myData->st;
    int end = myData->end;

    // Loop from start to end, printing each number with a 1-second delay
    for (int i = start; i <= end; i++)
    {
        printf("Thread 1: %d \n", i);

        // Sleep 1 second to simulate work and allow scheduler to switch threads
        sleep(1);
    }

    // Thread finishes here; return NULL to indicate no special status
    return NULL;
}

int main()
{
    pthread_t t1, t2; // Thread identifiers: opaque handles to the thread objects

    // Prepare data to pass to thread 1: print numbers 1 to 10
    struct myStruct myData1;
    myData1.st = 1;
    myData1.end = 10;

    // Prepare data to pass to thread 2: print numbers 11 to 20
    struct myStruct myData2;
    myData2.st = 11;
    myData2.end = 20;

    // Create thread 1:
    // Arguments:
    // &t1 -> pointer to thread handle storage
    // NULL -> default thread attributes (no special options)
    // myFn -> function pointer executed by thread
    // &myData1 -> argument to pass to thread function
    int checkThread1 = pthread_create(&t1, NULL, myFn, &myData1);

    // Create thread 2 similarly
    int checkThread2 = pthread_create(&t2, NULL, myFn, &myData2);

    // Check if thread 1 was created successfully
    if (checkThread1 != 0)
    {
        printf("Error in Creating Thread 1 \n");
        return 1; // Exit program on failure
    }

    // Main thread continues to run independently of thread 1 and 2
    // Prints numbers 21 to 29, with 2-second delay each
    // This runs concurrently with both threads
    for (int i = 21; i < 30; i++)
    {
        printf("Main Thread: %d \n", i);
        sleep(2); // Sleep 2 seconds simulates work and yields CPU to other threads
    }

    // pthread_join blocks main thread here until thread t1 finishes
    // This is necessary to prevent main thread from exiting before threads complete
    pthread_join(t1, NULL);

    // Wait for thread t2 to finish as well
    pthread_join(t2, NULL);

    // After both threads have finished, print final message
    printf("Main Thread, Thread 1, Thread 2 Has Finished! \n");

    // Explanation about compile command:
    // gcc myFile.c -o myFile -pthread
    // -pthread tells compiler and linker:
    // 1) Link with pthread library (libpthread.so)
    // 2) Enable threading-related flags and thread-safe libraries
    // This ensures pthread functions like pthread_create and pthread_join are linked correctly
    // And it avoids subtle bugs that arise from improper thread support

    return 0; // Exit program successfully
}
