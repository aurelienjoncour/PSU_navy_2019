/*
** EPITECH PROJECT, 2019
** PSU_my_printf
** File description:
** my_printf function
*/

#include <stdarg.h>
#include <stdbool.h>
#include "my_printf.h"

const struct choose_modulo opts[] = {
    { 'i', call_int},
    { 'd', call_int},
    { 's', call_str},
    { 'c', call_char},
    { '%', call_modulo},
    { 'b', call_binary},
    { 'o', call_octal},
    { 'u', call_unsigned},
    { 'x', call_hexa},
    { 'X', call_hexa_maj},
    { 'S', call_show_str},
    { 'p', call_pointer},
    { '\0', NULL}
};

const struct choose_flag flag_selec[] = {
    {'-', call_min},
    {'+', call_plus},
    {'0', call_zero},
    {' ', call_space},
    {'#', call_hashtag},
    {'\0', NULL}
};

static int exist_type(char c)
{
    for (int i = 0; opts[i].c != '\0'; i++)
        if (opts[i].c == c) {
            return i;
        }
    return -1;
}

static int exist_flags(char c)
{
    for (int i = 0; flag_selec[i].t != '\0'; i++)
        if (flag_selec[i].t == c) {
            return i;
        }
    return -1;
}

static arg_mod get_arg(char arg1, char arg2, arg_mod x)
{
    x.types = -1;
    x.flags = -1;
    if (exist_flags(arg1) != -1 && exist_type(arg2) != -1) {
        x.types = exist_type(arg2);
        x.flags = exist_flags(arg1);
        return x;
    }
    else if (exist_type(arg1) != -1) {
        x.types = exist_type(arg1);
        return x;
    }
    return x;
}

static int modulo(char c, va_list ap, va_list flag, arg_mod x)
{
    int i = 0;

    if (x.flags != -1) {
        flag_selec[x.flags].ptr(flag, opts[x.types].c);
        i++;
    }
    if (x.types != -1) {
        opts[x.types].fptr(ap);
        i++;
    }
    else
        my_putchar(c);
    return i;
}

int my_printf(char *str, ...)
{
    va_list ap;
    va_list flag;
    arg_mod x;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        va_copy(flag, ap);
        if (str[i] == '%') {
            x = get_arg(str[i + 1], str[i + 2], x);
            i += modulo(str[i], ap, flag, x);
        }
        else
            my_putchar(str[i]);
    }
    va_end(flag);
    va_end(ap);
    return 0;
}
