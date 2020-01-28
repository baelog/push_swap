/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/project.h"

void putstr_push_swap(char *str)
{
    int i = write(1, str, my_strlen(str) - 1);

    i = write(1, "\n", 1);
}

void print_list(list myList)
{
    list tmp = myList;
    int i;

    while (tmp) {
        my_put_nbr(tmp->data);
        i = write(1, "\n", 1);
        tmp = tmp->next;
    }
}

int is_sorted(list myList)
{
    list tmp = myList;
    int i;

    while (tmp->next) {
        if (tmp->data > tmp->next->data)
            return (0);
        tmp = tmp->next;
    }
    i = write(1, "\n", 1);
    return (1);
}

int main(int ac, char **av)
{
    list myList = NULL;
    list tmp = NULL;
    int numberOfNumber = all_in_the_list(&myList, &tmp, av);
    char *mouvement = malloc(sizeof(char) * (numberOfNumber * 32 * 2 * 3));
    char *keepPointer = mouvement;

    if (numberOfNumber == 0)
        return (0);
    algo(&myList, 1, &mouvement);
    if (myList->data > 0) {
        while (myList->prev->data < 0) {
            myList = myList->prev;
            stockrra(&mouvement);
        }
    }
    unlink_last_and_first(&myList);
    putstr_push_swap(keepPointer);
    free(keepPointer);
    destroy_list(myList);
    return (0);
}