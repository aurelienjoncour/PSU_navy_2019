/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game_prepare
*/

#include "navy.h"

int game_prepare(char ***map_enemy)
{
    *map_enemy = malloc(sizeof(char *) * (MAP_SIZE + 1));

    if (*map_enemy == NULL)
        return EXIT_ERROR;
    if (fill_game_board(*map_enemy))
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
