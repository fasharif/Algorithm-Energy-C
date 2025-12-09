#include "sorts.h"

static void swap(int *a, int *b, t_metrics *m) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    m->swaps++;
}

void bubble_sort(int *arr, size_t n, t_metrics *m) {
    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = 0; j < n - i - 1; j++) {
            m->comparisons++;
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1], m);
        }
}

void insertion_sort(int *arr, size_t n, t_metrics *m) {
    for (size_t i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            m->comparisons++;
            arr[j + 1] = arr[j];
            m->swaps++;
            j--;
        }
        arr[j + 1] = key;
    }
}

static int partition(int *arr, int low, int high, t_metrics *m) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        m->comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j], m);
        }
    }
    swap(&arr[i + 1], &arr[high], m);
    return i + 1;
}

void quick_sort(int *arr, int low, int high, t_metrics *m) {
    if (low < high) {
        int pi = partition(arr, low, high, m);
        quick_sort(arr, low, pi - 1, m);
        quick_sort(arr, pi + 1, high, m);
    }
}
