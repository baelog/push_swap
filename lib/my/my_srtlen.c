/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_srtlen.c
*/

#include "my.h"

int my_strlen(const char *str)
{
    int i;

    if (str == NULL)
        return 0;
    for (i = 0; str[i] != '\0'; ++i);
    return (i);
}

int my_len_array(char **tab)
{
    int i;

    if (tab == NULL)
        return 0;
    for (i = 0; tab[i] != NULL; ++i);
    return (i);
}
