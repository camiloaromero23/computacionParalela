#include "stdio.h"

#define STUDENTS_NUM 3

void setNums(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Insert the student's grade %d: ", i);
        scanf("%d", &nums[i]);
    }
}

int main()
{
    int grades[STUDENTS_NUM];
    setNums(grades, STUDENTS_NUM);

    for (int i = 0; i < STUDENTS_NUM; i++)
    {
        printf("Student %d grade is: %d\n", i, grades[i]);
    }

    // printf("Insert radius value\n");
    // scanf("%f", &radius);
    // printf("Area is %f\n", calculateArea(radius));
    return 0;
}
