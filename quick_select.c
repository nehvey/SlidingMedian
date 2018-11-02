#include "quick_select.h"
#include <stdlib.h>

int partition(float *list, int left, int right, int pivotIndex) {
    float pivotValue = list[pivotIndex];
    swap(&list[pivotIndex], &list[right]); // move pivot to the end
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (list[i] < pivotValue) {
            swap(&list[storeIndex], &list[i]);
            storeIndex++;
        }
    }
    swap(&list[right], &list[storeIndex]); // move pivot to its final place
    return storeIndex;
}

float sel(float *list, int left, int right, int k) {
    for (;;) {
        if (left == right) {
            return list[left];
        }
        int pivotIndex = left + (rand() % (right - left + 1)); // try median of 3
        pivotIndex = partition(list, left, right, pivotIndex);
        if (k == pivotIndex) {
            return list[k];
        } else if (k < pivotIndex) {
            right = pivotIndex - 1;
        } else {
            left = pivotIndex + 1;
        }
    }
}

void swap(float *i, float *k) {
    float tmp = *i;
    *i = *k;
    *k = tmp;
}
