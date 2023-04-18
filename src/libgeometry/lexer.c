#include "lexer.h"

int error(char* string)
{
    char circle[] = "circle";
    int i = 0;
    char* saver = string;
    int errors = 0;

    while (*string != 'c') {
        string++;
    }

    while ((*string != '(') && (*string != ')')) {
        if (*string != circle[i]) {
            printf("Error: expected 'circle', 'triangle' or 'polygon'\n");
            errors++;
        }
        i++;
        string++;
    }
    if (*string == ')') {
        printf("Error: expected '('\n");
        errors++;
    }
    string++;

    if ((*string == '(') || (*string == ')')) {
        printf("Error: unexpected brackets\n");
        errors++;
    }

    int dots = 0;
    int minuses = 0;
    int arg = 0;
    while (*string != ',') {
        if (*string == '.') {
            dots++;
        }
        if (*string == '-') {
            minuses++;
        }
        if ((*(string + 1) == ' ' || *(string + 1) == ',')
            && (*string >= 48 && *string <= 57)) {
            arg += 1;
        }
        if (dots > 2 || minuses > 2) {
            printf("Error: syntax error\n");
            errors++;
        }
        if ((*string != '.') && ((*string < '0') || (*string > '9'))
            && (*string != ' ') && (*string != '-')) {
            printf("Error: expected '<double>'\n");
            errors++;
        }
        string++;
    }
    string++;

    dots = 0;
    while ((*string != ')') && (*string != '(')) {
        if (*string >= 48 && *string <= 57
            && (*(string + 1) == ')' || *(string + 1) == ' ')) {
            arg += 1;
        }
        if (*string == '.') {
            dots++;
        }
        if (dots > 1) {
            printf("Error: syntax error\n");
            errors++;
        }
        if (*string == '-') {
            printf("Error: the radius cannot be negative\n");
            errors++;
        }
        if ((*string != '.') && ((*string < '0') || (*string > '9'))
            && (*string != ' ')) {
            printf("Error: expected '<double>'\n");
            errors++;
        }
        string++;
    }
    if (arg != 3) {
        printf("Error: undefined arguments\n");
        errors++;
    }
    if (*string == '(') {
        printf("Error: expected ')'\n");
        errors++;
    }
    string++;

    while ((*string != '\n') && (*string != '\0')) {
        if (*string != ' ') {
            printf("Error: unexpected token\n");
            errors++;
        }
        string++;
    }
    string = saver;
    if (errors == 0) {
        printf("Correct input!\n");
    }
    return errors;
}

void to_lower(char* string)
{
    for (int i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }
}

void to_string(char* string1, char* string2)
{
    int num = 0;
    for (int i = 0; i < strlen(string1); i++) {
        if (string1[i] != '\n') {
            string2[num++] = string1[i];
        } else {
            string1[num++] = '\0';
        }
    }
}