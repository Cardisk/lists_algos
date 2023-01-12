//
// Created by Matteo Cardinaletti on 11/01/23.
//

#ifndef SORT_SEARCH_ALGO_LINKED_LIST_H
#define SORT_SEARCH_ALGO_LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

/// Standard implementation of a Linked List
typedef struct l_list {
    int value;
    struct l_list *next;
} l_list;

/// Init for Linked List
l_list *l_init(int value) {
    // Creating a new list
    l_list *list = malloc(sizeof(l_list));

    // Storing value inside the variable
    list->value = value;

    // Make this node's next to point NULL
    list->next = NULL;

    // Return the list
    return list;
}

/// Add a new element in the first pos. inside the array
bool l_head_insert(l_list **list, int value) {
    // If the list is NULL, exit
    if (!list) return false;
    if (!(*list)) return false;

    // Creating a new node for the list
    l_list *new_node = malloc(sizeof(l_list));

    // Storing data inside the node
    new_node->value = value;

    // Make the node to point to the old head
    new_node->next = *list;

    // Updating the list to change the head
    *list = new_node;

    // Everything is fine, success
    return true;
}

/// Add a new value in the last pos. inside the array
bool l_tail_insert(l_list **list, int value) {
    // If the list is NULL, exit
    if (!list) return false;
    if (!(*list)) return false;

    // Creating a new node for the list
    l_list *new_node = malloc(sizeof(l_list));

    // Storing data inside the node
    new_node->value = value;

    // Make this node's next to point NULL
    new_node->next = NULL;

    // Storing the reference of the list to iterate over it
    l_list *it = *list;

    // Looping over the list to reach the last element
    while (it->next != NULL) it = it->next;

    // Updating the last element to point to the new one
    it->next = new_node;

    // Everything is fine, success
    return true;
}

/// Function to remove the first element of the array
bool l_pop_value(l_list **list, int *container) {
    // If the list is NULL, exit
    if (!list || !container) return false;
    if (!(*list)) return false;

    // Storing the first value inside the container ptr.
    *container = (*list)->value;

    // Storing the first node inside a temporary node
    l_list *node = *list;
    // Updating the list to remove the first element
    *list = (*list)->next;

    // Removing from the memory the old first node
    free(node);

    // Everything is fine, success
    return true;
}

void l_visit(l_list *list) {
    // If the list is NULL, exit
    if (!list) return;

    // Storing the reference of the list to iterate over it
    l_list *it = list;

    printf("List: \n\t");
    // Looping through the list to print it
    while (it != NULL) {
        // Print a [ then change the color to red
        printf("[ \033[0;31m");
        // Print the list value
        printf("%d", it->value);
        // Reset back to the default color, then print ]
        printf("\033[0m ]");

        if (it->next != NULL ) printf(" - ");

        // Updating the iterator
        it = it->next;
    }
}

bool l_ordered_insert(l_list **list, int value) {
    // If the list is NULL, exit
    if (!list) return false;
    if (!(*list)) return false;

    // Storing the reference of the list to iterate over it
    l_list *it = *list;

    // Store the last pos. where the iterator was
    l_list *last_pos = NULL;

    // Looping over the list to reach the last element
    while (it != NULL && it->value < value) {
        last_pos = it;
        it = it->next;
    }

    // If the last pos. of the iterator is still NULL, add the new value as the first one
    if (last_pos == NULL) {
        // Calling the relative function
        l_head_insert(list, value);

        // Everything is fine, success
        return true;
    }

    // If the iterator is NULL, add it from the tail
    if (it == NULL) {
        // Calling the relative function
        l_tail_insert(list, value);

        // Everything is fine, success
    }

    // Creating a new node for the list
    l_list *new_node = malloc(sizeof(l_list));

    // Storing data inside the node
    new_node->value = value;

    // Make this node's next to point to the iterator
    new_node->next = it;

    // Add the new node inside the list
    last_pos->next = new_node;

    // Everything is fine, success
    return true;
}

#endif //SORT_SEARCH_ALGO_LINKED_LIST_H
