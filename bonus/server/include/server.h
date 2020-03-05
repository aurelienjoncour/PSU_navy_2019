/*
** EPITECH PROJECT, 2020
** socket
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
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
int wait_connexion_to_server(int server_fd);

#endif /* !SERVER_H_ */
