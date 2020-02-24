/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** player
*/

#include "navy.h"

extern signal_info_t s;

int player_init(int player_id)
{
    if (player_id == 2) {
        s.signal_usr2 = 0;
        my_putstr("successfully connected\n\n");
    } else if (player_id != 1) {
        my_putstr_error("player() : invalid player id\n");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}
