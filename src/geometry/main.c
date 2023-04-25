#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libgeometry/calculator.h"
#include "libgeometry/lexer.h"
#include "libgeometry/parser.h"

int main(int argc, char** argv)
{
    FILE* file;
    char string1[40], string2[40];

    int count;
    printf("Введите количество окружностей: ");
    scanf("%d", &count);

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Could not open the file\n");
        return 0;
    }

    double radiuses[count];
    double points[count][2];
    double squares[count];
    double perimetrs[count];
    int j = 0;

    printf("Error chechking and getting data!\n\n");
    while (fgets(string1, 39, file) != NULL) {
        int errors;
        double *arguments;
        to_lower(string1);
        to_string(string1, string2);
        printf("%s\n\n", string2);
        errors = error(string2);
        if (errors == 0) {
            int i = 0;
            while (string2[i] != '(') {
                i++;
            }
            arguments = string_to_double(&string2[i + 1]);
            points[j][0] = *(arguments);
            points[j][1] = *(arguments + 1);
            radiuses[j] = *(arguments + 2);
            perimetrs[j] = circle_perimetr(*(arguments + 2));
            squares[j] = circle_square(*(arguments + 2));
            if (arguments != NULL) {
                free(arguments);
            }
            j++;
        }
        else
        {
            count--;
        }
        memset(string2, 0, sizeof(string2));
        printf("\n");
    }

    circle figures[count];

    for (int z = 0; z < count; z++)
    {
        figures[z].center.x = points[z][0];
        figures[z].center.y = points[z][1];
        figures[z].radius = radiuses[z]; 
        figures[z].square = squares[z];
        figures[z].perimetr = perimetrs[z];
    }

    int intersects[count][count];

    printf("Circle info:\n\n");

    if (count == 0)
    {
        printf("Circles not detected!\n");
    }

    for (int z = 0; z < count; z++)
    {
        print_circle(&figures[z]);
        printf("Intersects: \n");
        for (int y = 0; y < count; y++)
        {
            if (z != y)
            {
               intersects[z][y] = circle_collision(&figures[z], &figures[y]);
               if (intersects[z][y] != 0)
               {
                    printf("\t");
                    print_name(&figures[y]);
               }
            }
        }
        printf("--------------------\n");
        printf("\n");
    }

    fclose(file);
    return 0;
}