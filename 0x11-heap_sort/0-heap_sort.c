#include "sort.h"
/**
 * max_heap - binary distribution
 * @array: pointer to array
 * @size: actual size
 * @i: actual position
 * @total: total size
 */
void max_heap(int *array, int size, int i, size_t total)
{
	int max_num = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && array[left] > array[max_num])
		max_num = left;

	if (right < size && array[right] > array[max_num])
		max_num = right;

	if (max_num != i)
	{
		swap_num(&array[i], &array[max_num]);
		print_array(array, total);
		max_heap(array, size, max_num, total);
	}
}
/**
 * swap_num - change the value of two variable with pointers
 * @n: pointer for 1st variable
 * @m: pointer for 2nd variable
 */
void swap_num(int *n, int *m)
{
	int tmp = *n;
		*n = *m;
		*m = tmp;
}
/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: ptr for the array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t total = size;

	if (array != NULL)
	{
		for (i = size / 2 - 1; i >= 0; i--)
			max_heap(array, size, i, total);
		for (i = size - 1; i > 0; i--)
		{
			swap_num(&array[0], &array[i]);
			print_array(array, size);
			max_heap(array, i, 0, total);
		}
	}
}
