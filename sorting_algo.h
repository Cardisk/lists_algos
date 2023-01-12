//
// Created by Matteo Cardinaletti on 10/01/23.
//

#ifndef SORT_SEARCH_ALGO_SORTING_ALGO_H
#define SORT_SEARCH_ALGO_SORTING_ALGO_H

#include <stdlib.h>

// Returns a copy of the array
int *to_order(const int *array) {
    int *ordered = malloc(sizeof(int) * LEN);
    for (int i = 0; i < LEN; ++i) {
        ordered[i] = array[i];
    }
    return ordered;
}

// Selection sort
int *selection_sort(const int array[]) {
    int *ordered = to_order(array);

    int min;

    for (int i = 0; i < LEN - 1; ++i) {
        // Assuming the index of the min. value is the current pos.
        min = i;
        // Find the index of the min. value
        for (int j = i + 1; j < LEN; ++j) {
            if (ordered[j] < ordered[min]) min = j;
        }

        // Switching the min. value with the current one
        int tmp = ordered[min];
        ordered[min] = ordered[i];
        ordered[i] = tmp;
    }

    return ordered;
}

// Bubble sort
int *bubble_sort(const int array[]) {
    int *ordered = to_order(array);

    // Looping through all the elements until LEN - 2
    for (int i = 0; i < LEN - 1; ++i) {
        // Looping through all the elements until LEN - i - 1
        for (int j = 0; j < LEN - i - 1; ++j) {
            // Checking if the current value is greater than its next
            if (ordered[j] > ordered[j + 1]) {
                // Switching the values
                int tmp = ordered[j];
                ordered[j] = ordered[j + 1];
                ordered[j + 1] = tmp;
            }
        }
    }

    return ordered;
}

// Merge sort
void merge(int ordered[], int left, int middle, int right) {
    // Support variables
    int i = left, j = middle + 1, k = 0;
    // Temporary array
    int *t_arr = malloc(sizeof(int) * LEN);

    // Order the two side of the array
    while (i <= middle && j <= right) {
        t_arr[k] = (ordered[i] < ordered[j] ? ordered[i] : ordered[j]);
        (ordered[i] < ordered[j] ? i++ : j++);
        k++;
    }

    // If there is something left inside the right array, put it inside the temp. one
    while (i <= middle) {
        t_arr[k] = ordered[i];
        i++;
        k++;
    }

    // If there is something left inside the left array, put it inside the temp. one
    while (j <= right) {
        t_arr[k] = ordered[j];
        j++;
        k++;
    }

    // Now copy the ordered result from the temp. array to the actual one
    for (int x = left; x <= right; ++x) {
        ordered[x] = t_arr[x - left];
    }

    free(t_arr);
}

void merge_sort(int ordered[], int left, int right) {
    // If the two indexes are equals the array is divided into singular pieces, it can now be merged
    if (left >= right) return;

    // Establish the middle point to split the array
    int middle = (int) ((left + right) / 2);
    // Call recursively the function with the left side of the array
    merge_sort(ordered, left, middle);
    // Call recursively the function with the right side of the array
    merge_sort(ordered, middle + 1, right);
    // Merge both the sides
    merge(ordered, left, middle, right);
}

// Quick sort
void quick_sort(int array[], int left, int right) {
    // If the left index is equals to the right one, exit
    if (left == right) return;

    // Assuming the pivot as the first position
    int pivot = left;
    // Storing the length of the array or subarray
    int len = right;
    int tmp;

    // Looping until the condition is true
    while (left < right) {
        // Moving backwards the right index until the condition is true
        while (array[pivot] < array[right] && left < right) right--;

        // Moving forward the left index until the condition is true
        while (array[pivot] >= array[left] && left < right) left++;

        // If the two indexes are different switch the items
        if (left != right) {
            tmp = array[left];
            array[left] = array[right];
            array[right] = tmp;
        }
    }

    // If the pivot is equals to the left index, the array is sorted
    if (pivot == left) return;

    // Switching the pivot with the item into the left index position
    tmp = array[left];
    array[left] = array[pivot];
    array[pivot] = tmp;

    // Calling recursively the function with the left array and its bounds
    quick_sort(array, pivot, left - 1);
    // Calling recursively the function with the right array and its bounds
    quick_sort(array, left + 1, len);
}

#endif //SORT_SEARCH_ALGO_SORTING_ALGO_H
