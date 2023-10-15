#include <iostream>
#include <vector>
#include "func.h"

template <typename T>
void print_A(T& A) {
    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void quick_sort(T& A, int left, int right) {
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
    std::vector<int> vec = {6, 1, 5, 4, 9, 3, 7, 2, 0, 8, 11, 10};
    quick_sort(vec, 0, 11);
    std::cout << "quick sort test:" << std::endl;
    print_A(vec);
    return 0;
}