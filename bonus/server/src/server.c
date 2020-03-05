/*
** EPITECH PROJECT, 2020
** socket
** File description:
** server
*/

#include "server.h"

static int check_parameters(int ac, char **av)
{
    if (ac != 2) {
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

int main(int argc, char *argv[])
{
    int server_fd;
    int new_socket;
    char **map = NULL;
    int ret = check_parameters(argc, argv);

    if (ret != 1)
        return ret;
    map = game_map_load(argv[1]);
    if (!map)
        return EXIT_ERROR;
    server_fd = create_socket();
    if (server_fd == 0)
        return EXIT_ERROR;
    new_socket = wait_connexion_to_server(server_fd);
    if (new_socket == - 1)
        return EXIT_ERROR;
    if (navy(map, new_socket, 1) == EXIT_SUCCESS)
        show_game_status(map);
    free_2d_array(map);
    return 0;
}