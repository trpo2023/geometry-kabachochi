#include <ctest.h>
#include <math.h>

#include "libgeometry/calculator.h"
#include "libgeometry/lexer.h"
#include "libgeometry/parser.h"

CTEST(calculator, circle_perimetr_test)
{
    double radius = 5;
    double real, expected;
    expected = 2 * M_PI * radius;
    real = circle_perimetr(radius);

    ASSERT_DBL_NEAR(expected, real);
}

CTEST(calculator, circle_square_test)
{
    double radius = 5;
    double real, expected;
    expected = M_PI * radius * radius;
    real = circle_square(radius);

    ASSERT_DBL_NEAR(expected, real);
}

CTEST(calculator, point_distance_test)
{
    point first, second;
    double expected, real;
    first.x = 4;
    first.y = 5;
    second.x = 1;
    second.y = 1;

    expected = 5;
    real = point_distance(&first, &second);

    ASSERT_DBL_NEAR(expected, real);
}

CTEST(calculator, collision_test_true)
{
    circle first, second;

    first.center.x = 3;
    first.center.y = 3;
    first.radius = 6;
    second.center.x = 1;
    second.center.y = 1;
    second.radius = 8;

    ASSERT_TRUE(circle_collision(&first, &second));
}

CTEST(calculator, collision_test_false)
{
    circle first, second;

    first.center.x = 3;
    first.center.y = 3;
    first.radius = 6;
    second.center.x = 100;
    second.center.y = 100;
    second.radius = 8;

    ASSERT_FALSE(circle_collision(&first, &second));
}