/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** communicate : signal
*/

#include "navy.h"

extern signal_info_t s;

void handler(int sig, siginfo_t *siginfo, void *context)
{
    (void)context;
    if (sig == SIGUSR2 && s.signal_pid == 0) {
        s.signal_pid = siginfo->si_pid;
        return;
    }
    if (sig == SIGUSR1 && s.signal_pid == siginfo->si_pid)
        s.signal_usr1++;
    if (sig == SIGUSR2 && s.signal_pid == siginfo->si_pid)
        s.signal_usr2++;
}

void send_response(vector_t v, char **map_enemy)
{
    for (size_t i = 0; i < v.x; i++)
        kill_with_delay(s.signal_pid, SIGUSR1, 10000);
    kill_with_delay(s.signal_pid, SIGUSR2, 10000);
    for (size_t i = 0; i < v.y; i++)
        kill_with_delay(s.signal_pid, SIGUSR1, 10000);
    kill_with_delay(s.signal_pid, SIGUSR2, 10000);
    my_printf("%c%c: ", v.x + 'A', v.y + '1');
    while (s.signal_usr1 == 0 && s.signal_usr2 == 0);
    if (s.signal_usr1 == 1) {
        s.signal_usr1 = 0;
        update_game_map(map_enemy, &v, true);
    }
    if (s.signal_usr2 == 1) {
        s.signal_usr2 = 0;
        update_game_map(map_enemy, &v, false);
    }
}

vector_t receive_response(char **game_map)
{
    vector_t v = {0};

    while (s.signal_usr2 == 0);
    v.x = s.signal_usr1;
    s.signal_usr1 = 0;
    for (s.signal_usr2 = 0; s.signal_usr2 == 0;);
    v.y = s.signal_usr1;
    s.signal_usr1 = 0;
    s.signal_usr2 = 0;
    my_printf("%c%c: ", v.x + 'A', v.y + '1');
    if (game_map[v.y][v.x] == '.' || game_map[v.y][v.x] == 'o'
        || game_map[v.y][v.x] == 'x') {
        update_game_map(game_map, &v, false);
        kill_with_delay(s.signal_pid, SIGUSR2, 10000);
    }
    else {
        update_game_map(game_map, &v, true);
        kill_with_delay(s.signal_pid, SIGUSR1, 10000);
    }
    return v;
}

void wait_connection(void)
{
    my_putstr("waiting for enemy connection...\n\n");
    while (s.signal_pid == 0);
    my_putstr("enemy connected\n\n");
}

int kill_with_delay(pid_t pid, int signal, __useconds_t delay)
{
    int foo;

    foo = kill(pid, signal);
    usleep(delay);
    return foo;
}
