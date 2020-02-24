/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game
*/

#include "navy.h"

bool check_end(char **game_map)
{
    size_t nb_hit = 0;

    for (size_t i = 0; i < MAP_SIZE; i++)
        for (size_t j = 0; j < MAP_SIZE; j++)
            if (game_map[i][j] == 'x')
                nb_hit++;
    if (nb_hit == 14)
        return true;
    return false;
}
