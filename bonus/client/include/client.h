/*
** EPITECH PROJECT, 2020
** socket
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "navy.h"
#include "get_next_line.h"
#include "my_printf.h"
#include "ship_t.h"
#include "signal_info_t.h"
#include "word_array.h"

#define PORT 8080
#define EXIT_ERROR 84

//connexion
int create_socket(void);
int connect_to_server(int sock, char *ip_adress);

#endif /* !CLIENT_H_ */
