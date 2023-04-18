#include "calculator.h"

double circle_perimetr(double radius)
{
    double perimetr;
    perimetr = 2 * M_PI * radius;
    return perimetr;:::
}

double circle_square(double radius)
{
    double square;
    square = M_PI * radius * radius;
    return square;
}

void print_circle(double square, double perimetr)
{
    printf("--------------------\n");
    printf("Square = %f\n", square);
    printf("Perimetr = %f\n", perimetr);
    printf("--------------------\n");
}