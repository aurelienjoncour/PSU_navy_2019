/*
** EPITECH PROJECT, 2019
** PSU_my_printf
** File description:
** like %s but no printable char are represent whith / following by octal value
*/

#include <stdbool.h>
#include "my_printf.h"

static bool my_char_isprintable(char const c)
{
    if (c > 31 && c < 127)
        return true;
    else
        return false;
}

static int my_put_octal(char const c)
{
    my_putchar('\\');
    if (c < 8 ) {
        my_putstr("00");
        my_put_base(c, 8, "01234567");
    }
    else if (c > 7 && c < 127) {
        my_putchar('0');
        my_put_base(c, 8, "01234567");
    }
    else
        my_put_base(c, 8, "01234567");
    return 0;
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isprintable(str[i]))
            my_putchar(str[i]);
        else
            my_put_octal(str[i]);

    }
    return 0;
}
