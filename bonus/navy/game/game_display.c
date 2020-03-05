/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game display
*/

#include "navy.h"

void print_map(char **game, char *player)
{
    my_putstr(player);
    my_putstr(" |A B C D E F G H\n-+---------------\n");
    for (size_t i = 0; game[i] != NULL; i++) {
        my_printf("%d|", i + 1);
        for (size_t j = 0; game[i][j] != '\0'; j++)
            if (game[i][j + 1] != '\0')
                my_printf("%c ", game[i][j]);
            else
                my_printf("%c", game[i][j]);
        my_putchar('\n');
    }
    my_putstr("\n");
}

void print_2_map(char **game_map, char **map_enemy)
{
    print_map(game_map, ME);
    print_map(map_enemy, ENEMY);
}
