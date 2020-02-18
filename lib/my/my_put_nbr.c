/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display the number given as a parameter
*/

#include "my_printf.h"

static void put_nb_min(void)
{
    my_putstr("-2147483648");
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        put_nb_min();
        return (0);
    }
    if (nb < 0) {
        my_putstr("-");
        nb = nb * -1;
    } else if (nb == 0) {
        my_putstr("0");
        return (0);
    }
    if (nb/10 > 0)
        my_put_nbr(nb/10);
    my_putchar('0' + nb % 10);
    return (0);
}

int my_put_unsigned_int(unsigned int nb)
{
    if (nb == 0) {
        my_putstr("0");
        return 0;
    }
    if (nb / 10 > 0)
        my_put_nbr(nb / 10);
    my_putchar('0' + nb % 10);
    return 0;
}
