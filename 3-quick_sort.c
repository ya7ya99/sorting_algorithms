#include "sort.h"

/**
 * partitionArray - Implements the Lomuto partition scheme for Quicksort.
 * @array: The array to be sorted.
 * @lower: The starting index of the subarray to be partitioned.
 * @upper: The ending index of the subarray to be partitioned.
 * @size: The size of the array.
 */
void partitionArray(int *array, size_t lower, size_t upper, size_t size)
{
	int pivot = array[upper];
	int tmp;
	size_t pivotindex = lower;

	while (lower < upper)
	{
		if (array[lower] <= pivot)
		{
			tmp = array[pivotindex];
			array[pivotindex] = array[lower];
			array[lower] = tmp;
			print_array(array, size);
			pivotindex++;
		}
		lower++;
	}

	tmp = array[pivotindex];
	array[pivotindex] = array[upper];
	array[upper] = tmp;
	print_array(array, size);

	if (lower + 1 < pivotindex)
	{
		partitionArray (array, lower, pivotindex - 1, size);
	}
	if (pivotindex + 1 < upper)
	{
		partitionArray (array, pivotindex + 1, upper, size);
	}
}

/**
 * quick_sort - Sorts an array using the quicksort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	partitionArray (array, 0, size - 1, size);
}
