/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy
*/

#include "navy.h"

int navy(char **game_map, int socket, int player_id)
{
    char **map_enemy = NULL;

    if (game_prepare(&map_enemy) == EXIT_ERROR)
        return EXIT_ERROR;
    if (!map_enemy || !game_map) {
        my_putstr_error("navy : invalid game map\n");
        return EXIT_ERROR;
    }
    return player(map_enemy, game_map, player_id, socket);
}
