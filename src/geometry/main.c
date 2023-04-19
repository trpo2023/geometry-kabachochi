#include <libgeometry/calculator.h>
#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char** argv)
{
    FILE* file;
    char string1[40], string2[40];
    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Could not open the file\n");
        return 0;
    }

    while (fgets(string1, 39, file) != NULL) {
        int errors;
        double *arguments, square, perimetr;
        to_lower(string1);
        to_string(string1, string2);
        printf("%s\n", string2);
        printf("\n");
        errors = error(string2);
        if (errors == 0) {
            int i = 0;
            while (string2[i] != '(') {
                i++;
            }
            arguments = string_to_double(&string2[i + 1]);
            perimetr = circle_perimetr(*(arguments + 2));
            square = circle_square(*(arguments + 2));
            print_circle(square, perimetr);
            if (arguments != NULL)
            {
                free(arguments);
            }
        }
        printf("\n");
        memset(string2, 0, sizeof(string2));
    }

    fclose(file);
    return 0;
}