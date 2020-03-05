/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** usage
*/

#include "navy.h"

int usage(int status)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     navy_positions:");
    my_putstr("  file representing the positions of the ships.\n");
    return status;
}