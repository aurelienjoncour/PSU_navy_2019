/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game_map
*/

#include "navy.h"

void update_game_map(char **map, vector_t *v, bool hit)
{
    if (hit) {
        my_putstr("hit\n\n");
        map[v->y][v->x] = 'x';
    }
    else {
        my_putstr("missed\n\n");
        if (map[v->y][v->x] == '.')
            map[v->y][v->x] = 'o';
    }
}
