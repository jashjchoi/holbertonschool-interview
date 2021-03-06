#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sub(int *subarr, int *array, size_t left, size_t mid, size_t right);
void split_arr(int *subarr, int *array, size_t start, size_t end);
void merge_sort(int *array, size_t size);

#endif
