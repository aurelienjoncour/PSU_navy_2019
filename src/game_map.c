/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game_map
*/

#include "navy.h"

int fill_game_board(char **game_board)
{
    for (size_t i = 0; i < MAP_SIZE; i++) {
        game_board[i] = my_strdup("........");
        if (!game_board[i])
            return EXIT_FAILURE;
    }
    game_board[MAP_SIZE] = NULL;
    return EXIT_SUCCESS;
}

char **game_map(char **str)
{
    ship_t data[NB_SHIP] = {0};
    char **data_ship;

    if (!str || word_array_len(str) != NB_SHIP)
        return NULL;
    for (size_t i = 0; str[i] != NULL; i++) {
        data_ship = my_str_to_word_array(str[i], ":");
        if (!data_ship || error_data(data_ship))
            return NULL;
        parse_data(data, data_ship, i);
        free_2d_array(data_ship);
    }
    free_2d_array(str);
    if (wrong_number(data))
        return NULL;
    return fill_gameboard_data(data);
}

void update_game_map(char **map, vector_t *v, bool hit)
{
    if (hit) {
        my_putstr("hit\n\n");
        map[v->y][v->x] = 'x';
    }
    else {
        my_putstr("missed\n\n");
        map[v->y][v->x] = 'o';
    }
}