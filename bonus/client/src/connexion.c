/*
** EPITECH PROJECT, 2020
** socket
** File description:
** connexion
*/

#include <client.h>

int create_socket(void)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        my_putstr_error("Socket creation error\n");
        return EXIT_ERROR;
    }
    return sock;
}

int connect_to_server(int sock, char *ip_adress)
{
    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, ip_adress, &serv_addr.sin_addr) <= 0) {
        my_putstr_error("Invalid address/ Address not supported\n");
        return EXIT_ERROR;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        my_putstr_error("Connection Failed\n");
        return EXIT_ERROR;
    }
    my_putstr_error("succesfuly Connected\n");
    return 0;
}