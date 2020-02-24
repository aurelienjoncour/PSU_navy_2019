/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game_prepare
*/

#include "navy.h"

extern signal_info_t s;

int game_prepare(pid_t enemy_pid, char ***map_enemy)
{
    struct sigaction act = {0};
    *map_enemy = malloc(sizeof(char *) * (MAP_SIZE + 1));

    my_printf("my_pid: %d\n", getpid());
    if (*map_enemy == NULL)
        return EXIT_ERROR;
    if (fill_game_board(*map_enemy))
        return EXIT_ERROR;
    s.signal_pid = enemy_pid;
    act.sa_sigaction = &handler;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    if (s.signal_pid == 0)
        wait_connection();
    kill_with_delay(s.signal_pid, SIGUSR2, 10000);
    return EXIT_SUCCESS;
}
