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
    int col = 1;
    char circle[] = "circle";
    int i = 0;

    while (*string != 'c')
    {
        string++;
        col++;
    }

    while ((*string != '(') && (*string != ')'))
    {
        if (*string != circle[i])
        {
            printf("Error at column %d: expected 'circle', 'triangle' or 'polygon'\n", i + 1);
            exit(EXIT_FAILURE);
        }
        i++;
        string++;
        col++;
    }
    if (*string == ')')
    {
        printf("Error at column %d: expected '('\n", col);
        exit(EXIT_FAILURE);
    }
    string++;
    col++;

    if ((*string == '(') || (*string == ')'))
    {
        printf("Error at column %d: expected '<double>'\n", col);
        exit(EXIT_FAILURE);
    }

    while (*string != ',')
    {
        if ((*string != '.') && ((*string < '0') || (*string > '9')) && (*string != ' ') && (*string != '-'))
        {
            printf("Error at column %d: expected '<double>'\n", col);
            exit(EXIT_FAILURE);
        }
        string++;
        col++;
    }
    string++;
    col++;

    while ((*string != ')') && (*string != '('))
    {
        if (*string == '-')
        {
            printf("Error at column %d: the radius cannot be negative\n", col);
            exit(EXIT_FAILURE);
        }
        if ((*string != '.') && ((*string < '0') || (*string > '9')) && (*string != ' '))
        {
            printf("Error at column %d: expected '<double>'\n", col);
            exit(EXIT_FAILURE);
        }
        string++;
        col++;
    }
    if (*string == '(')
    {
        printf("Error at column %d: expected ')'\n", col);
        exit(EXIT_FAILURE);
    }
    string++;
    col++;

    while ((*string != '\n') && (*string != '\0'))
    {
        if (*string != ' ')
        {
            printf("Error at column %d: unexpected token\n", col);
            exit(EXIT_FAILURE);
        }
        string++;
        col++;
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