#include <stdio.h>
#include <omp.h>

int main()
{

    int threadId, threadNum;

    // threadId is specified as private so that each thread will have its own copy of threadId

#pragma omp parallel private(threadId)
    {
        threadId = omp_get_thread_num();
        printf("Hola mundo desde el hilo %d\n", threadId);

        // Sync barrier is created
        // Master waits for all to be finished to print
#pragma omp barrier
        if (threadId == 0)
        {
            threadNum = omp_get_num_threads();
            printf("Total threads: %d\n", threadNum);
        }
    }
    return 0;
}
