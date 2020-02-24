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
