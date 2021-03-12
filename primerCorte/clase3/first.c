#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void initArray(int randomRange, int ARR_SIZE, double arr1[], double arr2[], double arr3[])
{

    time_t t;

    srand((unsigned)time(&t));

    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr1[i] = rand() % randomRange;
        arr2[i] = rand() % randomRange;
        arr3[i] = 0;
    }
}

void printArray(int size, double array[])
{
    for (int i = 0; i < size; i++)
    {
        printf(" %f", array[i]);
    }
}

int main(int argc, char **argv)
{
    int ARR_SIZE = (int)atof(argv[1]);
    int randomRange = (int)atof(argv[2]);

    double arr1[ARR_SIZE], arr2[ARR_SIZE], result[ARR_SIZE];

    initArray(randomRange, ARR_SIZE, arr1, arr2, result);

    printf("Array 1\n");
    printArray(ARR_SIZE, arr1);

    printf("\nArray 2\n");
    printArray(ARR_SIZE, arr2);

    printf("\nArray 3\n");
    printArray(ARR_SIZE, result);

    printf("\n");

    return 0;
}
