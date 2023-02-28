#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Point {
    double x;
    double y;
} point;

typedef struct Circle {
    point center;
    double radius;
} circle;

void error(char *string)
{
    char circle[] = "circle";
    int i = 0;

    while (*string != 'c')
    {
        string++;
    }

    while ((*string != '(') && (*string != ')'))
    {
        if (*string != circle[i])
        {
            printf("Error: expected 'circle', 'triangle' or 'polygon'\n");
            exit(EXIT_FAILURE);
        }
        i++;
        string++;
    }
    if (*string == ')')
    {
        printf("Error: expected '('\n");
        exit(EXIT_FAILURE);
    }
    string++;

    if ((*string == '(') || (*string == ')'))
    {
        printf("Error: expected '<double>'\n");
        exit(EXIT_FAILURE);
    }

    int dots = 0;
    int minuses = 0;
    while (*string != ',')
    {
        if (*string == '.')
        {
            dots++;
        }
        if (*string == '-')
        {
            minuses++;
        }
        if (dots > 2 || minuses > 2)
        {
            printf("Error: syntax error\n");
            exit(EXIT_FAILURE);
        }
        if ((*string != '.') && ((*string < '0') || (*string > '9')) && (*string != ' ') && (*string != '-'))
        {
            printf("Error: expected '<double>'\n");
            exit(EXIT_FAILURE);
        }
        string++;
    }
    string++;

    dots = 0;
    while ((*string != ')') && (*string != '('))
    {
        if (*string == '.')
        {
            dots++;
        }
        if (dots > 1)
        {
            printf("Error: syntax error\n");
            exit(EXIT_FAILURE);
        }
        if (*string == '-')
        {
            printf("Error: the radius cannot be negative\n");
            exit(EXIT_FAILURE);
        }
        if ((*string != '.') && ((*string < '0') || (*string > '9')) && (*string != ' '))
        {
            printf("Error: expected '<double>'\n");
            exit(EXIT_FAILURE);
        }
        string++;
    }
    if (*string == '(')
    {
        printf("Error: expected ')'\n");
        exit(EXIT_FAILURE);
    }
    string++;

    while ((*string != '\n') && (*string != '\0'))
    {
        if (*string != ' ')
        {
            printf("Error: unexpected token\n");
            exit(EXIT_FAILURE);
        }
        string++;
    }
}

void to_lower(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = tolower(string[i]);
    }
}

void to_string(char *string1, char *string2)
{
    int num = 0;
    for (int i = 0; i < strlen(string1); i++)
    {
        if (string1[i] != '\n')
        {
            string2[num++] = string1[i];
        }
        else
        {
            string1[num++] = '\0';
        }
    }
}

int main(int argc, char** argv)
{
    FILE *file;
    char string1[40], string2[40];
    if ((file = fopen(argv[1], "r")) == NULL)
    {
        printf("Could not open the file\n");
        return 0;
    }
    
    while (fgets(string1, 39, file) != NULL)
    {
        to_lower(string1);
        to_string(string1, string2);
        printf("%s\n", string2);
        error(string2);
        memset(string2, 0, sizeof(string2));
    }

    fclose(file);
    return 0;
}