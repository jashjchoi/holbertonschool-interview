#include "sort.h"
/**
* merge_sort - sort by merging with subarray
* @array: array to sort
* @size: size of the array
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (!array || size == 1)
		return;
	arr = malloc(sizeof(int) * size);
	split_arr(arr, array, 0, size);
	free(arr);
}

/**
 * merge_sub - merges subarray sub with passed in array
 * @subarr: copy of the array
 * @array: array to merge
 * @left: prev index
 * @mid: middle index
 * @right: next index
 * Return: void
 */
void merge_sub(int *subarr, int *array, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] < array[j])
			subarr[k++] = array[i++];
		else
			subarr[k++] = array[j++];
	}
	while (i < mid)
		subarr[k++] = array[i++];

	while (j < right)
		subarr[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = subarr[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
* split_arr - recursively call to get middle
* @subarr: subarray to merge
* @array: input array
* @start: start index
* @end: end index
* Return: void
*/
void split_arr(int *subarr, int *array, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = (end - start) / 2 + start;
		split_arr(subarr, array, start, mid);
		split_arr(subarr, array, mid, end);
		merge_sub(subarr, array, start, mid, end);
	}
}