/*
** EPITECH PROJECT, 2019
** PSU_my_printf
** File description:
** other flags gestions
*/

#include <stdarg.h>
#include "my_printf.h"

int call_show_str(va_list ap)
{
    my_showstr(va_arg(ap, char *));
    return 0;
}
