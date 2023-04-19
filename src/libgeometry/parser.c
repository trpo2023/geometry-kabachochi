#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

void correct_form(char* string)
{
    int i, j;
    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] == ',') {
            for (j = i; string[j] != '\0'; j++) {
                string[j] = string[j + 1];
            }
            i--;
        }
    }
}

double* string_to_double(char* string)
{
    correct_form(string);
    double* result;
    char* tstring; // указатель на непреобразованную часть строки
    char* nstring
            = string; // указатель для определения завершения преобразования

    result = malloc(3 * sizeof(double));
    for (int i = 0; i < 3; i++) {
        tstring = nstring;
        result[i] = strtod(nstring, &nstring);
        if (result == 0 && tstring == nstring) {
            break;
        }
    }
    return result;
}