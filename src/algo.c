/*
** EPITECH PROJECT, 2019
** algo of push_swap
** File description:
** binary radix sort for push_swap
*/

#include "../include/my.h"
#include "../include/project.h"

void algo(list *myListA, int theBitCompare, char **mouvement)
{
    list myListB = NULL;
    list tmp = (*myListA)->prev;
    int a = 1;

    while (*myListA != tmp) {
        if (((*myListA)->data & theBitCompare) && a) {
            tmp = *myListA;
            --a;
        }
        if (!((*myListA)->data & theBitCompare))
            first_lista_to_first_listb(&(*myListA), &myListB, &(*mouvement));
        else {
            *myListA = (*myListA)->next;
            stockra(&(*mouvement));
        }
    }
    while (myListB)
        first_listb_to_first_lista(&(*myListA), &myListB, &(*mouvement));
    if (theBitCompare << 1)
        algo(&(*myListA), theBitCompare << 1, &(*mouvement));
}

void first_lista_to_first_listb(list *myListA, list* myListB, char **mouvement)
{
    list tmp = *myListA;

    if ((*myListA)->next != *myListA) {
        (*myListA) = (*myListA)->next;
        (*myListA)->prev->prev->next = (*myListA);
        (*myListA)->prev = tmp->prev;
    }
    else
        myListA = NULL;
    tmp->next = (*myListB);
    tmp->prev = NULL;
    (*myListB) = tmp;
    stockpb(&(*mouvement));
}

void first_listb_to_first_lista(list *myListA, list* myListB, char **mouvement)
{
    list tmp = *myListB;

    (*myListB) = (*myListB)->next;
    if (*myListA) {
        tmp->next = (*myListA);
        tmp->prev = (*myListA)->prev;
        (*myListA)->prev->next = tmp;
        (*myListA)->prev = tmp;
        (*myListA) = tmp;
    }
    else {
        tmp->prev = tmp;
        tmp->next = tmp;
        *myListA = tmp;
    }
    stockpa(&(*mouvement));
}