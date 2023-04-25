#include <math.h>
#include <stdio.h>

#include "calculator.h"

double circle_perimetr(double radius)
{
    double perimetr;
    perimetr = 2 * M_PI * radius;
    return perimetr;
}

double circle_square(double radius)
{
    double square;
    square = M_PI * radius * radius;
    return square;
}

double point_distance(const point* first, const point* second)
{
    double result
            = sqrt(pow(first->x - second->x, 2) + pow(first->y - second->y, 2));
    return result;
}

int circle_collision(const circle* first, const circle* second)
{
    double dist, rad;
    dist = point_distance(&(first->center), &(second->center));
    rad = first->radius + second->radius;
    if (dist <= rad)
        return 1;
    else
        return 0;
}

void print_circle(circle* result)
{
    print_name(result);
    printf("--------------------\n");
    printf("Square = %f\n", result->square);
    printf("Perimetr = %f\n", result->perimetr);
}

void print_name(circle* result)
{
    printf("circle(%f %f, %f)\n",
           result->center.x,
           result->center.y,
           result->radius);
}