/*
** EPITECH PROJECT, 2019
** project fuction
** File description:
** project.h
*/

#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

typedef struct list_s {
    int data;
    struct list_s *next;
    struct list_s *prev;
}list_t, *list;

void link_last_and_first(list *, list *);
void unlink_last_and_first(list *);

void first_lista_to_first_listb(list*, list*, char**);
void first_listb_to_first_lista(list*, list*, char**);
void algo(list *, int, char **);

void stockra(char**);
void stockpa(char**);
void stockpb(char**);
void stockrra(char**);

int all_in_the_list(list*, list*, char**);

void putstr_push_swap(char*);

void destroy_list(list);

int is_sorted(list myList);
