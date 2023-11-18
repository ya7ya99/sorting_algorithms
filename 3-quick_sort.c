#include "sort.h"

/**
 * partition - function sort a partition
 * @array: variable int
 * @start: variable int
 * @end: variable int
 * @size: variable size
 * Return: int
 */

int partition(int *array, int start, int end, size_t size)
{
	int i = start, j, pivot = array[end], tmp;

	for (j = start; j <= end; j++)
	{
		if (array[j] < pivot)
		{
			if (array[i] != array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[end])
	{
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort - function sorts an array of integers in ascending
 * @array: variable int
 * @start: variable int
 * @end: variable int
 * @size: variable size
 */

void quicksort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start >= end)
	{
		return;
	}
	pivot = partition(array, start, end, size);
	quicksort(array, start, pivot - 1, size);
	quicksort(array, pivot + 1, end, size);
}

/**
 * quick_sort - function sorts an array of integers in ascending
 * @array: variable int
 * @size: variable size
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
