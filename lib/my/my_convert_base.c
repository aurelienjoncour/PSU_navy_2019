/*
** EPITECH PROJECT, 2019
** PSU_my_printf
** File description:
** convert base
*/

#include "my_printf.h"

int my_put_base(long int nb, int nb_base, char *base)
{
    if (nb / nb_base > 0)
        my_put_base(nb / nb_base, nb_base, base);
    my_putchar(base[nb % nb_base]);
    return 0;
}