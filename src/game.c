/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game
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

bool check_end(char **game_map)
{
    size_t nb_hit = 0;

    for (size_t i = 0; i < MAP_SIZE; i++)
        for (size_t j = 0; j < MAP_SIZE; j++)
            if (game_map[i][j] == 'x')
                nb_hit++;
    if (nb_hit == 14)
        return true;
    return false;
}

bool write_attack(vector_t *v)
{
    char *str;

    while (1) {
        my_putstr("attack: ");
        str = get_next_line(STDIN_FILENO);
        if (str == NULL)
            break;
        if (my_strlen(str) != 2) {
            my_putstr("wrong position\n");
            continue;
        }
        v->x = POS_X(str[0]);
        v->y = POS_Y(str[1]);
        if (v->y > MAP_SIZE || v->x > MAP_SIZE) {
            my_putstr("wrong position\n");
            continue;
        }
        return true;
    }
    return false;
}

int kill_with_delay(pid_t pid, int signal, __useconds_t delay)
{
    int foo;

    foo = kill(pid, signal);
    usleep(delay);
    return foo;
}