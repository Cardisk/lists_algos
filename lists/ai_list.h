//
// Created by Matteo Cardinaletti on 11/01/23.
//

#ifndef SORTING_ALGO_AI_LIST_H
#define SORTING_ALGO_AI_LIST_H

#include <stdlib.h>
#include <stdbool.h>

/// Record struct to contain a value
typedef struct record {
    int value;
    int next;
} record;

/// Array-Index list. It simulates two lists, one for the empty spots and one for the full ones
typedef struct ai_list {
     record *buffer;
     int size;

     int first;
     int free;
} ai_list;

/// Init for the Array-Index List
ai_list *ai_init(int size) {
    // If the size is equals to 0, exit
    if (size <= 0) return NULL;

    // Creating a new list
    ai_list *list = malloc(sizeof(ai_list));

    // Creating a new buffer of the given size
    list->buffer = malloc(sizeof(record) * size);

    // Assigning data to the variables
    list->size = size;
    list->first = size;
    list->free = 0;

    // Setting all the next pos. to the right item
    for (int i = 0; i < size; ++i) list->buffer[i].next = i + 1;

    // Return the list
    return list;
}

/// Add a new element in the first pos. inside the array
bool ai_head_insert(ai_list *list, int value) {
    // If the list is NULL, exit
    if (!list) return false;

    // If the list is full, exit
    if (list->free == list->size) return false;

    // Store the first free space inside the array
    int old_free = list->free;
    // Update the first free space inside the array
    list->free = list->buffer[list->free].next;

    // Store the new value inside the array
    list->buffer[old_free].value = value;
    // Update the new value to point to the old first pos.
    list->buffer[old_free].next = list->first;

    // Update the first pos.
    list->first = old_free;

    // Everything is fine, success
    return true;
}

/// Add a new value in the last pos. inside the array
bool ai_tail_insert(ai_list *list, int value) {
    // If the list is NULL, exit
    if (!list) return false;

    // If the list is full, exit
    if (list->free == list->size) return false;

    // Store the first free space inside the array
    int old_free = list->free;
    // Update the first free space inside the array
    list->free = list->buffer[list->free].next;

    // Store the new value inside the array
    list->buffer[old_free].value = value;
    // Updating the buffer next to point to NULL
    list->buffer[old_free].next = list->size;

    // Store the first full pos. to iterate over the array
    int it = list->first;

    // If the iterator contains immediately the size, this is the first element added
    if (it == list->size) {
        // Update the first full space flag of the list
        list->first = old_free;

        // Everything is fine, success
        return true;
    }

    // Looping to reach the last full item inside the array
    while (list->buffer[it].next != list->size) it = list->buffer[it].next;

    // Update the old last element to point to the new item stored
    list->buffer[it].next = old_free;

    // Everything is fine, success
    return true;
}

/// Print the given Array-Index List
void ai_visit(ai_list list) {
    printf("List: \n\t");
    int it = list.first;
    while (list.buffer[it].next != list.size) {
        // Print a [ then change the color to red
        printf("[ \033[0;31m");
        // Print the array value
        printf("%d", list.buffer[it].value);
        // Reset back to the default color, then print ]
        printf("\033[0m ]");

        // Print " - " if the item is not the first or the last one of the array
        printf(" - ");

        // Update the iterator to point to the next item
        it = list.buffer[it].next;
    }

    // Print it again because one is skipped by the while
    printf("[ \033[0;31m");
    printf("%d", list.buffer[it].value);
    printf("\033[0m ]");
}

/// Insert the new value inside the correct position to maintain an ordered aspect
bool ai_ordered_insert(ai_list *list, int value) {
    // If the list is NULL, exit
    if (!list) return false;

    // If the list is full, exit
    if (list->free == list->size) return false;

    // Store the first free space inside the array
    int old_free = list->free;
    // Update the first free space inside the array
    list->free = list->buffer[list->free].next;

    // Store the first full pos. to iterate over the array
    int it = list->first;
    // Store the last pos. where the iterator was
    int last_pos = -1;
    // Update the old last element to point to the new item stored
    while (list->buffer[it].next != list->size && list->buffer[it].value < value) {
        // If the value is bigger than the one inside the array, store this as last pos.
        last_pos = it;
        // Go to the next full element
        it = list->buffer[it].next;
    }

    // If the last pos. of the iterator is still -1, add the new value as the first one
    if (last_pos == -1) {
        // Calling the relative function
        ai_head_insert(list, value);

        // Everything is fine, success
        return true;
    }

    // If the iterator is equals to the list size, add it from the tail
    if (list->buffer[it].next == list->size) {
        // Calling the relative function
        ai_tail_insert(list, value);

        // Everything is fine, success
        return true;
    }

    // Store inside the old free pos. the new value
    list->buffer[old_free].value = value;
    // Make the old free pos. to point to the first item bigger than the new value
    list->buffer[old_free].next = it;

    // Make the last pos. to point to the new value just added
    list->buffer[last_pos].next = old_free;

    // If the last pos. of the iterator was the first one, update it
    if (last_pos == list->first) list->first = old_free;

    // Everything is fine, success
    return true;
}

// TODO: function get to retrieve a value (Bald man didn't do this one)

// search function is a simply sequential algorithm over the array, watch it on "searching-algo.h"

#endif //SORTING_ALGO_AI_LIST_H
