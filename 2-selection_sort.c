#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	int smallest_index, temp;
	size_t i, j;

	if (!array || !size)
		return;

	i = 0;
	while (i < size - 1)
	{
		smallest_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest_index])
				smallest_index = j;
		}
		if (smallest_index != (int)i)
		{
			temp = array[smallest_index];
			array[smallest_index] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		i++;
	}
}
