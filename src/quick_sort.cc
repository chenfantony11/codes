#include <stdio.h>
#include "func.h"

void print_A(int* A, int left, int size) {
    int i = 0;
    for (; i <= size; i++) {
        printf("%d ", A[left + i]);
    }
    printf("\n");
}

void quick_sort(int* A, int left, int right) {
    int pivot = A[left];
    int i = left + 1, j = right, pos, tmp;
    if (left >= right) {
        return;
    }

    for (; j > i; j--) {
        if (A[j] < pivot) {
            for (; i < j; i++) {
                if (A[i] > pivot) {
                    tmp = A[j];
                    A[j] = A[i];
                    A[i] = tmp;
                    break;
                }
            }
        }
    }
    if (A[i] < pivot) {
        pos = i;
    } else if (A[i] > pivot) {
        pos = i - 1;
    }
    tmp = A[pos];
    A[pos] = pivot;
    A[left] = tmp;

    quick_sort(A, left, pos - 1);
    quick_sort(A, pos + 1, right);
}

int quick_sort_test() {
    int Array[] = {6, 1, 5, 4, 9, 3, 7, 2, 0, 8, 11, 10};
    quick_sort(Array, 0, sizeof(Array)/ sizeof(int) - 1);
    print_A(Array, 0, sizeof(Array)/sizeof(int) - 1);
    return 0;
}