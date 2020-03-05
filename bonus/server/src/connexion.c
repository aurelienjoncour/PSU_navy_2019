/*
** EPITECH PROJECT, 2020
** socket
** File description:
** connexion
*/

#include "server.h"

int create_socket(void)
{
    int server_fd = 0;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        my_putstr_error("Socket creation error\n");
        return 0;
    }
    return server_fd;
}

int init_server(int server_fd, struct sockaddr_in *address)
{
    int opt = 1;

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        my_putstr_error("error on init_server");
        return EXIT_ERROR;
    }
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)address, sizeof(*address)) < 0) {
        my_putstr_error("bind failed\n");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int wait_connexion_to_server(int server_fd)
{
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int new_socket = 0;

    if (init_server(server_fd, &address) == EXIT_ERROR)
        return -1;
    my_putstr("waiting for enemy connection...\n\n");
    if (listen(server_fd, 3) < 0) {
        my_putstr_error("error in function listen\n");
        return -1;
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
        (socklen_t*)&addrlen)) < 0) {
        my_putstr_error("error in function accept\n");
        return -1;
    }
    my_putstr("enemy connected\n\n");
    return new_socket;
}