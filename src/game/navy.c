/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy
*/

#include "navy.h"

signal_info_t s = {0};

int navy(char **game_map, pid_t enemy_pid)
{
    char **map_enemy = NULL;

    if (game_prepare(enemy_pid, &map_enemy) == EXIT_ERROR)
        return EXIT_ERROR;
    if (!map_enemy || !game_map) {
        my_putstr_error("navy : invalid game map\n");
        return EXIT_ERROR;
    }
    if (s.signal_usr2 == 1)
        return player_2(map_enemy, game_map);
    else
        return player_1(map_enemy, game_map);
    return 0;
}
