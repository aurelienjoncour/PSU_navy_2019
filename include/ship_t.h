/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** ship_t
*/

#ifndef SHIP_T_H_
#define SHIP_T_H_

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    size_t x;
    size_t y;
}vector_t;

typedef struct {
    vector_t start;
    vector_t end;
    int size;
}ship_t;

#endif /* !SHIP_T_H_ */
