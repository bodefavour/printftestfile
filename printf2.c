#include "main.h"

int _printf(const char *format, ...)
{
    int print_allchars = 0;

    va_list list_of_allargs;

    if (format == NULL)
        return (-1);

    va_start(list_of_allargs, format);

    while(*format){
        if (*format == '%'){
            format++;
            if (*format == '%'){
                print_allchars += fputchar('%');
            }
            else if (*format == 'c'){
                char c = va_arg(list_of_allargs, int);
                write(1, &c, 1);
                print_allchars++;
            }
            else if (*format == 's'){
                print_allchars += _putws(va_arg(list_of_allargs, char *));
            }
        }
        else{
            print_allchars += fputchar(*format);
        }
        format++;
    }

    va_end(list_of_allargs);

    return list_of_allargs;

}

int main(){
    _printf("Leo\n");
    _printf("Leo %c\n", 'L');
}