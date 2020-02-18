/*
** EPITECH PROJECT, 2019
** PSU_my_printf
** File description:
** basics flags of my_printf
*/

#include <stddef.h>
#include <stdarg.h>
#include "my_printf.h"

int call_str(va_list ap)
{
    my_putstr(va_arg(ap, char *));
    return 0;
}

int call_int(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
    return 0;
}

int call_char(va_list ap)
{
    my_putchar(va_arg(ap, int));
    return 0;
}

int call_modulo(va_list ap)
{
    my_putchar('%');
    return 0;
}

int call_pointer(va_list ap)
{
    long int ptr = va_arg(ap, void *);

    if (ptr == 0)
        my_putstr("(nil)");
    else {
        my_putstr("0x");
        my_put_base(ptr, 16, "0123456789abcdef");
    }
    return 0;
}
