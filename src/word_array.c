/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** word_array
*/

#include "navy.h"

void free_2d_array(char **array)
{
    if (array == NULL)
        return;
    for (size_t i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

size_t word_array_len(char **array)
{
    size_t i = 0;

    for (i = 0; array[i] != NULL; i++);
    return i;
}

char **word_array_dup(char **env)
{
    char **dup;
    size_t size = word_array_len(env);

    dup = malloc(sizeof(char *) * (size + 1));
    if (dup == NULL)
        return NULL;
    for (size_t i = 0; env[i]; i++)
        dup[i] = my_strdup(env[i]);
    dup[size] = NULL;
    return dup;
}

char **word_array_realloc(char **env)
{
    char **dup;
    size_t size = word_array_len(env);

    dup = malloc(sizeof(char *) * (size + 2));
    if (dup == NULL)
        return NULL;
    for (size_t i = 0; env[i]; i++)
        dup[i] = my_strdup(env[i]);
    dup[size] = NULL;
    dup[size + 1] = NULL;
    return dup;
}