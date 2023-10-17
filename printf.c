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
                print_allchars += _putchar('%');
            }
            else if (*format == 'c'){
                print_allchars += _putchar(va_arg(list_of_allargs, int));
            }
            else if (*format == 's'){
                print_allchars += _puts(va_arg(list_of_allargs, char *));
            }
            else if (*format == 'd' || *format == 'i'){
                print_allchars += print_number(va_arg(list_of_allargs, int));
            }
            else if (*format == 'b'){
                print_allchars += print_binary(va_arg(list_of_allargs, int));
            }
            else if (*format == 'u'){
                print_allchars += print_unsigned(va_arg(list_of_allargs, int));
            }
            else if (*format == 'o'){
                print_allchars += print_octal(va_arg(list_of_allargs, int));
            }
            else if (*format == 'x'){
                print_allchars += print_hex(va_arg(list_of_allargs, int));
            }
            else if (*format == 'X'){
                print_allchars += print_HEX(va_arg(list_of_allargs, int));
            }
            else if (*format == 'r'){
                print_allchars += print_rev(va_arg(list_of_allargs, char *));
            }
            else if (*format == 'R'){
                print_allchars += print_rot13(va_arg(list_of_allargs, char *));
            }
            else if (*format == 'p'){
                print_allchars += print_address(va_arg(list_of_allargs, void *));
            }
            else if (*format == 'S'){
                print_allchars += print_S(va_arg(list_of_allargs, char *));
            }
            else if (*format == '\0'){
                return (-1);
            }
            else{
                print_allchars += _putchar('%');
                print_allchars += _putchar(*format);
            }
        }
        else{
            print_allchars += _putchar(*format);
        }
        format++;
    }

    va_end(list_of_allargs);

    return list_of_allargs;

}

int main(){
    _printf("Leo\n");
}