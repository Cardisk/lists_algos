//
// Created by Matteo Cardinaletti on 10/01/23.
//

#ifndef SORT_SEARCH_ALGO_SEARCHING_ALGO_H
#define SORT_SEARCH_ALGO_SEARCHING_ALGO_H

#include <stdbool.h>
#include <math.h>

int sequential_search(const int array[], const int target) {
    // The array can be sorted or not, the research is done sequentially so nothing changes
    for (int i = 0; i < LEN; ++i) {
        // If the item at the current position is equals to the target, return the index
        if (array[i] == target) return i;
    }

    // If the element is not present inside the array, exit
    return -1;
}

int binary_search(const int array[], const int target, const int left, const int right) {
    // If the left bound is greater than the right one, the item is not present inside the array, exit
    if (left >= right) return -1;

    // Estimating the middle point of the array
    int middle = right - (right - left) / 2;

    // If the target is equals to the middle item, return the current pos.
    if (array[middle] == target) return middle;

    // If the target is less than the middle one, search inside the right part of the array
    if (target < array[middle])
        return binary_search(array, target, left, middle - 1);
    // If the target is greater than the middle one, search inside the left part of the array
    else
        return binary_search(array, target, middle, right);
}

int jump_search(const int array[], const int length, const int target) {
    // Estimating optimal jump
    int optimal_jump = (int) sqrt(length);

    int i = 0;
    // Jumping through the array until an item is greater than target
    while (i + optimal_jump <= length) {
        if (array[i] < target) i += optimal_jump;
        else break;
    }

    // Moving backwards inside the array until the item is found
    while(i >= 0) {
        if (array[i] == target) return i;
        i--;
    }

    // Target is not present inside the array, exits
    return -1;
}

#endif //SORT_SEARCH_ALGO_SEARCHING_ALGO_H
