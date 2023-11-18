#include "sort.h"

/**
 * partitionArray - Partitions an array around a pivot element.
 * @array: Pointer to the array to be partitioned.
 * @lower: Lower bound of the subarray to be partitioned.
 * @uper: Upper bound of the subarray to be partitioned.
 * @size: Size of the array.
 * Return: Index of the pivot element after partitioning.
 */
size_t partitionArray(int *array, size_t lower, size_t uper, size_t size)
{
	size_t start, end;
	int pivot = array[lower];
	int tmp;
	start = lower;
	end = uper;

	while (start < end)
	{
		while (array[start] <= pivot)
			start++;
		while (array[end] > pivot)
			end--;
		if (start < end)
		{
			tmp = array[start];
			array[start] = array[end];
			array[end] = tmp;
			print_array(array, size);
		}
	}
	tmp = array[lower];
	array[lower] = array[end];
	array[end] = tmp;
	print_array(array, size);
	return (end);
}

/**
 * sort_helper - Recursively sorts a subarray using quicksort.
 * @array: Pointer to the array to be sorted.
 * @lower: Lower bound of the subarray to be sorted.
 * @uper: Upper bound of the subarray to be sorted.
 * @size: Size of the array.
 */
void sort_helper(int *array, size_t lower, size_t uper, size_t size)
{
	size_t loc;

	if (lower < uper)
	{
		loc = partitionArray(array, lower, uper, size);
		sort_helper(array, lower, loc - 1, size);
		sort_helper(array, loc + 1, uper, size);
	}
}

/**
 * quick_sort - Sorts an array using the quicksort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	sort_helper(array, 0, size - 1, size);
}
