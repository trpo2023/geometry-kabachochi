#include <ctest.h>
#include <string.h>

#include "libgeometry/calculator.h"
#include "libgeometry/lexer.h"
#include "libgeometry/parser.h"

CTEST(lexer, error_true)
{
    char circle[] = "circle(1.033 -34.5, 30)";

    int expected = 0;
    int real = error(circle);

    ASSERT_EQUAL(expected, real);
}

CTEST(lexer, error_false)
{
    char circle[] = "circle(x23 32, 43)";

    int expected = 1;
    int real = error(circle);

    ASSERT_EQUAL(expected, real);
}
