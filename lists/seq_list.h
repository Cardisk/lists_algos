//
// Created by Matteo Cardinaletti on 11/01/23.
//

#ifndef SORT_SEARCH_ALGO_SEQ_LIST_H
#define SORT_SEARCH_ALGO_SEQ_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/// Sequential list implemented as a circular buffer
typedef struct seq_list {
    int *buffer;                // Circular buffer
    int size;                   // Buffer size

    int head;                   // First index full
    int tail;                   // First index empty

} seq_list;

/// Init for the Sequential List
seq_list *seq_init(int size) {
    // If the buffer size is 0, exit
    if (size <= 0) return NULL;

    // Create a new list
    seq_list *list = malloc(sizeof(seq_list));

    // Initialize the buffer with the given size
    list->buffer = malloc(sizeof(int) * size);

    // Assign the values to the right variables
    list->size = size;
    list->head = 0;
    list->tail = 0;

    // Return the list
    return list;
}

/// Add a new element in the first pos. inside the array
bool seq_head_insert(seq_list *list, int value) {
    // If the list is NULL, exit
    if (!list) return false;

    // If the list is full, exit
    if ((list->tail + 1) % list->size == list->head) return false;

    // If the head isn't on the first pos. of the array, go back by one
    if (list->head != 0) list->head--;
    // If the head is on the first pos. of the array, go to the last one
    else list->head = list->size - 1;

    // Add the new value inside the array
    list->buffer[list->head] = value;

    // Everything is fine, success
    return true;
}

/// Add a new value in the last pos. inside the array
bool seq_tail_insert(seq_list *list, int value) {
    // If the list is NULL, exit
    if (!list) return false;

    // If the list is full, exit
    if ((list->tail + 1) % list->size == list->head) return false;

    // If the tail is equals to the size - 1, reset it to 0
    if (list->tail == list->size - 1) list->tail = 0;

    // Add the new value inside the array
    list->buffer[list->tail++] = value;

    // Everything is fine, success
    return true;
}

/// Print the given Sequential List
void seq_visit(seq_list list) {
    printf("List: \n\t");
    for (int i = list.head; i != list.tail; i = (i + 1) % list.size) {
        // Print " - " if the item is not the head or tail of the array
        if (i != list.head && i != list.tail) printf(" - ");
        // Print a [ then change the color to red
        printf("[ \033[0;31m");
        // Print the array value
        printf("%d", list.buffer[i]);
        // Reset back to the default color, then print ]
        printf("\033[0m ]");
    }
}

// TODO: function get to retrieve a value (Bald man didn't do this one)

// search function is a simply sequential algorithm over the array, watch it on "searching-algo.h"

#endif //SORT_SEARCH_ALGO_SEQ_LIST_H
