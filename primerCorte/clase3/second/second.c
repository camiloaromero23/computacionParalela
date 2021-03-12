#include <stdio.h>
#include "functions.h"

int main()
{
    int a, b;
    printf("Enter two numbers:\n");
    if (scanf("%d %d", &a, &b) != 2)
    {
        fputs("Invalid input!", stderr);
        return 1;
    }

    printf("%d + %d = %d\n", a, b, Sum(a, b));
    return 0;
}
