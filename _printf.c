#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list arg;
    int printed_chars = 0;
    int i;

    va_start(arg, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'c':
                    printed_chars += printf("%c", va_arg(arg, int));
                    break;
                case 's':
                    printed_chars += printf("%s", va_arg(arg, char *));
                    break;
                case '%':
                    printed_chars += printf("%%");
                    break;
                default:
                    printed_chars += printf("%%%c", format[i]);
                    break;
            }
        } else {
            putchar(format[i]);
            printed_chars++;
        }
    }

    va_end(arg);

    return printed_chars;
}
