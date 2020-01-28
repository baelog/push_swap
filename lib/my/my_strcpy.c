/*
** EPITECH PROJECT, 2019
** strcopy
** File description:
** copy
*/

#include "my.h"

char *my_strcpy(char const *src)
{
    int i;
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (i = 0; src[i]; ++i)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}

char **my_array_cpy(char **src)
{
    int y = 0;
    int x = 0;
    char **array = malloc(sizeof(char*) * (my_len_array(src) + 1));

    for (y = 0; src[y]; ++y) {
        array[y] = malloc(sizeof(char) * (my_strlen(src[y]) + 1));
        for (x = -1; src[y][++x]; array[y][x] = src[y][x]);
        array[y][x] = '\0';
    }
    array[y] = NULL;
    return (array);
}
