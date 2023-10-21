#include <iostream>

/*
 * @brief   heap sort algorithm
 * use heap to sort can only O(nlogn) time
 * heap: array
 * use big (or small) root heap to sort out the biggest number
 * each time, swap the root node with the last node
 * 
 * heap sort always can be used to get the top k number from list.
 * just need to build a heap with the top k size array, and then
 *  use heap sort. the top one will be the top k number.
 */
static int array[10] = {1, 6, 3, 4, 7, 8, 5, 2, 10, 9};
static int size = sizeof(array) / sizeof(int);

int swap(int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
  
    return 0;
}

int siftdown(int i, int size) {
    int j, k;
    int tmp, flag = 0;

    while((i <= size / 2  - 1) && flag == 0) {
     /* get the left child node */
        j = 2 * i + 1;
        /* get the right child node */
        k = 2 * i + 2;
        /* get the largest child node */
        if (j < size && array[j] > array[i]) {
            tmp = j;
        } else {
            tmp = i;
        }
        if (k < size && array[k] > array[tmp]) {
            tmp = k;
        }
        /* if tmp is not the largest child node, swap it */
        if (tmp != i) {
            swap(i, tmp);
            i = tmp;
        } else {
            flag = 1;
        }
    }
    return 0;
}

int create_big_root_heap(int* array, int size) {
    int i;
    /* build a big root heap, from the non-leaf node */
    for (i = size / 2 - 1; i >= 0; i--) {
        siftdown(i, size);
    }
    return 0;
}

int heap_sort(int* array, int size) {
    int i;

    create_big_root_heap(array, size);

    for (i = size - 1; i >= 0;) {
        swap(0, i);
        /*
         * due to array has been heapified,
         * after swap out, only the root node
         * need to shfitdown to maintain heap property
         */
        siftdown(0, i--);
    }
    return 0;
}

int heap_sort_test() {
    int i = 0;

    heap_sort(array, size);
    std::cout << "heap sort test: " << size << std::endl;
    for (i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}