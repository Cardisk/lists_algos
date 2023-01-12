#include <stdio.h>

#define LEN 10
#include "sorting_algo.h"
#include "searching_algo.h"
#include "bald-lists.h"

void sorting(const int array[], int **ordered) {
    // Unsorted array
    printf("Unsorted: ");
    for (int i = 0; i < LEN; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Selection sort + print
    *ordered = selection_sort(array);

    printf("Selection sort: ");
    for (int i = 0; i < LEN; ++i) {
        printf("%d ", (*ordered)[i]);
    }
    printf("\n");

    // Bubble sort + print
    *ordered = bubble_sort(array);

    printf("Bubble sort: ");
    for (int i = 0; i < LEN; ++i) {
        printf("%d ", (*ordered)[i]);
    }
    printf("\n");

    // Merge sort + print
    *ordered = to_order(array);
    merge_sort(*ordered, 0, LEN - 1);

    printf("Merge sort: ");
    for (int i = 0; i < LEN; ++i) {
        printf("%d ", (*ordered)[i]);
    }
    printf("\n");

    // Quick sort + print
    *ordered = to_order(array);
    quick_sort((*ordered), 0, LEN - 1);

    printf("Quick sort: ");
    for (int i = 0; i < LEN; ++i) {
        printf("%d ", (*ordered)[i]);
    }
    printf("\n");
}

void searching(const int array[], int target) {
    // Sequential search
    printf("Sequential search: %d\n", sequential_search(array, target));

    // Binary search
    printf("Binary search: %d\n", binary_search(array, target, 0, LEN - 1));

    // Jump_search
    printf("Jump search: %d\n", jump_search(array, LEN - 1, target));
}

void lists() {
    // Sequential seq + all of its functions
    printf("Sequential List: \n");

    seq_list *seq = seq_init(10);
    seq_tail_insert(seq, 4);
    seq_tail_insert(seq, 5);
    seq_tail_insert(seq, 6);

    seq_head_insert(seq, 0);
    seq_head_insert(seq, 1);
    seq_head_insert(seq, 2);
    seq_head_insert(seq, 3);

    seq_visit(*seq);

    printf("\n\n");

    // Array-Index seq + all of its functions
    printf("Array-Index List: \n");

    ai_list *ai = ai_init(10);
    ai_tail_insert(ai, 4);
    ai_tail_insert(ai, 5);
    ai_tail_insert(ai, 6);

    ai_head_insert(ai, 0);
    ai_head_insert(ai, 1);
    ai_head_insert(ai, 2);
    ai_head_insert(ai, 3);

    ai_visit(*ai);

    printf("\n\n");

    printf("Linked List: \n");

    l_list *link = l_init(4);
    l_tail_insert(&link, 5);
    l_tail_insert(&link, 6);

    l_head_insert(&link, 0);
    l_head_insert(&link, 1);
    l_head_insert(&link, 2);
    l_head_insert(&link, 3);

    l_visit(link);

    printf("\n\n");

}

int main() {
    // Original array init
    int array[LEN] = {4, 3, 1, 5, 6, 10,9, 7, 2, 8};
    // Ordered array init
    int **ordered = malloc(sizeof(int*) * LEN);

    // Calling sorting algorithms
    sorting(array, ordered);

    printf("\n");

    // Calling searching algorithms
    searching(*ordered, 11);

    printf("\n");

    // Calling Bald's lists implementations
    lists();

    printf("\n");

    return 0;
}
