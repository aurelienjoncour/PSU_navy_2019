/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "navy.h"

int main(int ac, char **av)
{
    char **game = NULL;
    pid_t enemy_pid = 0;

    if (ac < 2 || ac > 3)
        return EXIT_ERROR;
    if (!my_strcmp(av[1], "-h"))
        return usage(0);
    if (ac == 2)
        game = game_map(read_entiere_file(av[1]));
    if (ac == 3) {
        enemy_pid = my_getnbr(av[1]);
        game = game_map(read_entiere_file(av[2]));
    }
    if (!game)
        return EXIT_ERROR;
    my_printf("my_pid: %d\n", getpid());
    if (!navy(game, enemy_pid))
        my_putstr(check_end(game) ? LOOSE : WIN);
    free_2d_array(game);
    return 0;
}