#include "sort.h"

/**
 * hoare_partition - function sort a partition
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * Return: int
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1, tmp;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * quicksorthoare - function Quick sort algorithm using Hoare scheme
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 */
void quicksorthoare(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		quicksorthoare(array, low, pivot - 1, size);
		quicksorthoare(array, pivot, high, size);
	}
}

/**
 * quick_sort_hoare - function to initiate Quick sort using Hoare scheme
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksorthoare(array, 0, size - 1, size);
}
