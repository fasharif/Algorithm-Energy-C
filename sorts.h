#ifndef SORTS_H
#define SORTS_H

#include <stddef.h>

typedef struct s_metrics {
    unsigned long comparisons;
    unsigned long swaps;
} t_metrics;

void bubble_sort(int *arr, size_t n, t_metrics *m);
void insertion_sort(int *arr, size_t n, t_metrics *m);
void quick_sort(int *arr, int low, int high, t_metrics *m);

#endif
