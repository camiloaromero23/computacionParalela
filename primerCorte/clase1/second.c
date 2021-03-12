#include <stdio.h>

const float PI = 3.14;
float radius;

int main()
{
    float area;

    printf("Enter radius of a circle: ");
    scanf("%f", &radius);
    area = PI * radius * radius;
    printf("Area of circle with radius %f is: %f\n", radius, area);

    return 0;
}
