#include "stdio.h"

#define ARRAY_SIZE 3

void setNums(int nums[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Insert the value #%d: ", i);
        scanf("%d", &nums[i]);
    }
}

void sumArray(int totalSum[], int firstArray[], int secondArray[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        totalSum[i] = firstArray[i] + secondArray[i];
    }
}

void printArray(int array[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Array value in pos %d is: %d\n", i, array[i]);
    }
}

int main()
{
    int totalSum[ARRAY_SIZE];

    int firstArray[ARRAY_SIZE];
    int secondArray[ARRAY_SIZE];

    printf("Insert the %d value(s) in the first array:\n", ARRAY_SIZE);
    setNums(firstArray);

    printf("Insert the %d value(s) in the second array:\n", ARRAY_SIZE);
    setNums(secondArray);

    sumArray(totalSum, firstArray, secondArray);

    printArray(totalSum);

    return 0;
}
