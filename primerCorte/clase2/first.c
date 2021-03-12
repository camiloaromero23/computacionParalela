#include "stdio.h"

#define PI 3.14
#define perror(x) printf("Error: %s \n", x)

float calculateArea(float radius)
{
    float area = PI * radius * radius;
    return area;
}

int main()
{

    float radius;
    printf("Insert radius value\n");
    scanf("%f", &radius);
    printf("Area is %f\n", calculateArea(radius));
    return 0;
}
