#pragma once

typedef struct Point {
    double x;
    double y;
} point;

typedef struct Circle {
    point center;
    double radius;
    double perimetr;
    double square;
} circle;

double circle_perimetr(double radius);

double circle_square(double radius);

double point_distance(const point* first, const point* second);

int circle_collision(const circle* first, const circle* second);

void print_circle(circle* result);

void print_name(circle* result);
