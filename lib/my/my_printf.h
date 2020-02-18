/*
** EPITECH PROJECT, 2019
** PSU_my_printf
** File description:
** structure for my_printf
*/

#include <stdarg.h>
#include <stddef.h>

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

int my_printf(char *str, ...);

void my_putchar(unsigned char c);

int my_put_nbr(int nb);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_printf(char *str, ...);

int call_int(va_list ap);

int call_str(va_list ap);

int call_char(va_list ap);

int call_modulo(va_list ap);

int call_binary(va_list ap);

int call_octal(va_list ap);

int call_unsigned(va_list ap);

int call_hexa(va_list ap);

int call_hexa_maj(va_list ap);

int call_show_str(va_list ap);

int call_pointer(va_list ap);

int my_put_base(long int nb, int nb_base, char *base);

int my_showstr(char const *str);

int my_put_unsigned_int(unsigned int nb);

int call_hashtag(va_list ap, char type);

int call_zero(va_list ap, char type);

int call_min(va_list ap, char type);

int call_plus(va_list ap, char type);

int call_space(va_list ap, char type);

typedef struct choose_modulo choose_modulo;

struct choose_modulo {
    char c;
    int (*fptr)(va_list);
};

typedef struct choose_flag choose_flag;

struct choose_flag {
    char t;
    int (*ptr)(va_list, char);
};

typedef struct arg_mod arg_mod;

struct arg_mod {
    int flags;
    int types;
};

#endif