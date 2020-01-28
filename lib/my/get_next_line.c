/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** bsq.c
*/

#include "my.h"
#define READ_SIZE 1

char *my_strcat_twice(char *str1, char *str2)
{
    char *str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2));
    int a = -1;

    for (int i = -1; str1[++i]; str[++a] = str1[i]);
    if (str2)
        for (int i = -1; str2[++i] && str2[i - 1] != '\n'; str[++a] = str2[i]);
    str[++a] = '\0';
    return (str);
}

void reduce_buff(char **str, char *buff)
{
    int a = 0;
    int i = -1;

    str[0][my_strlen(*str) - 1] = '\0';
    while (buff[i - 1] != '\n')
        ++i;
    for (a = 0; buff[i]; ++a, ++i) {
        buff[a] = buff[i];
    }
    buff[a] = '\0';
}

char *get_next_line(int fd)
{
    static char buff[READ_SIZE + 1];
    char *str = "\0";
    int rd;

    str = my_strcat_twice(str, buff);
    if (*str) {
        if (str[my_strlen(str) - 1] == '\n') {
            reduce_buff(&str, buff);
            return (str);
        }
    }
    while ((rd = read(fd, buff, READ_SIZE)) > 0) {
        str = my_strcat_twice(str ,buff);
        if (str[my_strlen(str) - 1] == '\n') {
            reduce_buff(&str, buff);
            return (str);
        }
    }
    return ((*str) ? (buff[0] = '\0' ,(str)) : NULL);
}
