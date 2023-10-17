#include "main.h"

int _printf(const char *format, ...)
{
    int print_allchars = 0;

    va_list list_of_allargs;

    if (format == NULL)
        return (-1);

    va_start(list_of_allargs, format);