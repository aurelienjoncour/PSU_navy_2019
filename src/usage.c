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
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     ");
    my_putstr("first_player_pid:  ");
    my_putstr("only for the 2nd player. pid of the first player.\n");
    my_putstr("     navy_positions:");
    my_putstr("  file representing the positions of the ships.\n");
    return status;
}