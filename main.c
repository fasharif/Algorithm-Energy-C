#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

#define SIZE 1000

static double benchmark(void (*sort_fn)(int *, size_t, t_metrics *),
                        int *arr, size_t n, t_metrics *m) {
    clock_t start = clock();
    sort_fn(arr, n, m);
    return (double)(clock() - start) / CLOCKS_PER_SEC;
}

static void fill_random(int *arr, size_t n) {
    for (size_t i = 0; i < n; i++)
        arr[i] = rand() % 10000;
}

int main(void) {
    srand((unsigned)time(NULL));
    FILE *f = fopen("data.csv", "w");
    fprintf(f, "algorithm,time_sec,comparisons,swaps\n");

    int *arr = malloc(SIZE * sizeof(int));
    int *copy = malloc(SIZE * sizeof(int));
    t_metrics m;
    double time_spent;

    const char *names[] = {"bubble", "insertion", "quick"};
    for (int i = 0; i < 3; i++) {
        fill_random(arr, SIZE);
        for (size_t j = 0; j < SIZE; j++) copy[j] = arr[j];
        m.comparisons = m.swaps = 0;

        if (i == 0) time_spent = benchmark(bubble_sort, copy, SIZE, &m);
        else if (i == 1) time_spent = benchmark(insertion_sort, copy, SIZE, &m);
        else {
            clock_t start = clock();
            quick_sort(copy, 0, SIZE - 1, &m);
            time_spent = (double)(clock() - start) / CLOCKS_PER_SEC;
        }

        fprintf(f, "%s,%.6f,%lu,%lu\n", names[i], time_spent, m.comparisons, m.swaps);
    }

    fclose(f);
    free(arr);
    free(copy);
    printf("Results saved to data.csv\n");
    return 0;
}
