#include <ctest.h>
#include <stdlib.h>
#include <string.h>

#include "libgeometry/calculator.h"
#include "libgeometry/lexer.h"
#include "libgeometry/parser.h"

CTEST(parser, string_to_double)
{
    double real[3] = {2, 3, -5};
    char string[] = "2 3, -5";
    double* expected;

    expected = string_to_double(string);

    ASSERT_DBL_NEAR(expected[0], real[0]);
    ASSERT_DBL_NEAR(expected[1], real[1]);
    ASSERT_DBL_NEAR(expected[2], real[2]);

    free(expected);
}
