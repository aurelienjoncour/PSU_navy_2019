/*
** EPITECH PROJECT, 2019
** PSU_my_printf
** File description:
** flags for my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include "my_printf.h"

int call_hashtag(va_list flag, char type)
{
    unsigned int nb  = va_arg(flag, unsigned int);

    if (nb == 0)
        return 0;
    if (type == 'o')
        my_putchar('0');
    if (type == 'X')
        my_putstr("0X");
    if (type == 'x')
        my_putstr("0x");
    return 0;
}

int call_plus(va_list flag, char type)
{
    int nb = 0;

    if (type == 'd' || type == 'i') {
        nb = va_arg(flag, int);
        if (nb > - 1)
            my_putchar('+');
        else
            return 0;
    }
    return 0;
}

int call_space(va_list flag, char type)
{
    int nb = 0;

    if (type == 'd' || type == 'i') {
        nb = va_arg(flag, int);
        if (nb > -1)
            my_putchar(' ');
        else
            return 0;
    }
    return 0;
}

int call_min(va_list flag, char type)
{
    return 0;
}

int call_zero(va_list flag, char type)
{
    return 0;
}
