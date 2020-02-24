/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "navy.h"

static int check_parameters(int ac, char **av)
{
    if (ac < 2 || ac > 3) {
        my_putstr_error("main : use -h flag too see help\n");
        return EXIT_ERROR;
    }
    if (!my_strcmp(av[1], "-h"))
        return usage(EXIT_SUCCESS);
    return 1;
}

static void show_game_status(char **map)
{
    bool status = check_end(map);

    if (status)
        my_putstr(MSG_LOOSE);
    else
        my_putstr(MSG_WIN);
}

int main(int ac, char **av)
{
    char **map = NULL;
    pid_t enemy_pid = 0;
    int ret;

    ret = check_parameters(ac, av);
    if (ret != 1)
        return ret;
    if (ac == 2) {
        map = game_map_load(av[1]);
    } else if (ac == 3) {
        enemy_pid = my_getnbr(av[1]);
        map = game_map_load(av[2]);
    }
    if (!map)
        return EXIT_ERROR;
    if (navy(map, enemy_pid) == EXIT_SUCCESS)
        show_game_status(map);
    free_2d_array(map);
    return 0;
}
