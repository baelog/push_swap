/*
** EPITECH PROJECT, 2019
** push_swap chain list gestion
** File description:
** creation/destruction of list and creation/destruction of circular list
*/

#include "../include/my.h"
#include "../include/project.h"

void destroy_list(list myList)
{
    list tmp = myList;

    while (myList->next) {
        tmp = myList;
        myList = myList->next;
        myList->prev = NULL;
        free(tmp);
    }
    free(myList);
}

int add_node(list *myList, int data)
{
    list newNode = malloc(sizeof(list_t));

    if (!newNode)
        return 84;
    newNode->data = data;
    newNode->next = NULL;
    if (!(*myList)) {
        newNode->prev = NULL;
        *myList = newNode;
    }
    else {
        newNode->prev = *myList;
        (*myList)->next = newNode;
    }
    return 0;
}

int all_in_the_list(list *myList, list *tmp, char **av)
{
    int numberOfNumber = 0;

    for (int i = 1; av[i]; ++i) {
        add_node(&(*myList), my_getnbr(av[i]));
        (!(*myList)->next) ? (*tmp = *myList) : (*myList = (*myList)->next);
        ++numberOfNumber;
    }
    if (is_sorted(*tmp)) {
        destroy_list(*tmp);
        return (0);
    }
    link_last_and_first(&(*tmp), &(*myList));
    return (numberOfNumber);
}

void link_last_and_first(list *first, list *last)
{
    (*first)->prev = *last;
    (*last)->next = *first;
    *last = (*last)->next;
}

void unlink_last_and_first(list *myList)
{
    (*myList)->prev->next = NULL;
    (*myList)->prev = NULL;
}