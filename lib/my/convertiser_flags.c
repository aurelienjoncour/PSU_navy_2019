/*
** EPITECH PROJECT, 2019
** PSU_my_printf
** File description:
** flags convertiser
*/

#include <stdarg.h>
#include "my_printf.h"

int call_octal(va_list ap)
{
    my_put_base(va_arg(ap, unsigned int), 8, "01234567");
    return 0;
}

int call_unsigned(va_list ap)
{
    my_put_unsigned_int(va_arg(ap, unsigned int));
    return 0;
}

int call_binary(va_list ap)
{
    my_put_base(va_arg(ap, unsigned int), 2, "01");
    return 0;
}

int call_hexa(va_list ap)
{
    my_put_base(va_arg(ap, unsigned int), 16, "0123456789abcdef");
    return 0;
}

int call_hexa_maj(va_list ap)
{
    my_put_base(va_arg(ap, unsigned int), 16, "0123456789ABCDEF");
    return 0;
}
