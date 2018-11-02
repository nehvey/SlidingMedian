#ifndef QUICK_SELECT_H
#define QUICK_SELECT_H

int partition(float *list, int left, int right, int pivotIndex);

float sel(float *list, int left, int right, int k);

void swap(float *i, float *k);

#endif
