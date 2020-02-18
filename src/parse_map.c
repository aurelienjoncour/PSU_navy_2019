/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** parse_map
*/

#include "navy.h"

void parse_data(ship_t *data, char **data_ship, int i)
{
    data[i].size = my_getnbr(data_ship[0]);
    data[i].start.x = POS_X(data_ship[1][0]);
    data[i].start.y = POS_Y(data_ship[1][1]);
    data[i].end.x = POS_X(data_ship[2][0]);
    data[i].end.y = POS_Y(data_ship[2][1]);
}

char **fill_gameboard_data(ship_t *data)
{
    char **game_board = malloc(sizeof(char *) * (MAP_SIZE + 1));
    vector_t v;

    if (!game_board || fill_game_board(game_board))
        return NULL;
    for (size_t i = 0; i < NB_SHIP; i++) {
        v.x = data[i].start.x;
        v.y = data[i].start.y;
        for (; v.x <= data[i].end.x && v.y == data[i].end.y; v.x++)
            game_board[v.y][v.x] = data[i].size + '0';
        for (; v.y <= data[i].end.y && v.x == data[i].end.x; v.y++)
            game_board[v.y][v.x] = data[i].size + '0';
    }
    return game_board;
}