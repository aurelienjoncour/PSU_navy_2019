/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game_map
*/

#include "navy.h"

static int game_map_check_parameter(char **map)
{
    if (!map || word_array_len(map) != NB_SHIP) {
        my_putstr_error("game_map_check: invalid map length\n");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

char **game_map_check(char **map)
{
    ship_t data[NB_SHIP] = {0};
    char **data_ship;

    if (game_map_check_parameter(map) == EXIT_ERROR)
        return NULL;
    for (size_t i = 0; map[i] != NULL; i++) {
        data_ship = my_str_to_word_array(map[i], ":");
        if (!data_ship || error_data(data_ship)) {
            my_putstr_error("game_map_check: map content error\n");
            return NULL;
        }
        parse_data(data, data_ship, i);
        free_2d_array(data_ship);
    }
    if (wrong_number(data)) {
        my_putstr_error("game_map_check: wrong number error\n");
        return NULL;
    }
    return fill_gameboard_data(data);
}
