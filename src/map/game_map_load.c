/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** load_game_map
*/

#include "navy.h"

char **game_map_load(char *file_path)
{
    char **map = read_entiere_file(file_path);
    char **map_checked = game_map_check(map);

    free_2d_array(map);
    return map_checked;
}
