/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** siginfo_t
*/

#ifndef SIGINFO_T_H_
#define SIGINFO_T_H_

typedef struct {
    int signal_usr1;
    int signal_usr2;
    int signal_pid;
}signal_info_t;

#endif /* !SIGINFO_T_H_ */
