#include "sort.h"

/**
 * find_max_value - Find the maximum value in the array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * Return: int
 */
int find_max_value(int *array, size_t size)
{
	int max_value = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
		{
			max_value = array[i];
		}
	}
	return (max_value);
}

/**
 * counting_sort - Sorts an array using the Counting Sort algorithm.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max_value, i, *counting_array, *result_array;

	if (array == NULL || size < 2)
		return;
	counting_array = malloc(sizeof(int) * size);
	if (counting_array == NULL)
		return;
	max_value = find_max_value(array, size);
	result_array = malloc((max_value + 1) * sizeof(int));
	if (result_array == NULL)
	{
		free(counting_array);
		return;
	}
	for (i = 0; i < (max_value + 1); i++)
	{
		result_array[i] = 0;
	}
	for (i = 0; i < (int)size; i++)
	{
		result_array[array[i]]++;
	}
	for (i = 0; i < (max_value + 1); i++)
		result_array[i] += result_array[i - 1];
	print_array(result_array, max_value + 1);
	for (i = 0; i < (int)size; i++)
	{
		counting_array[result_array[array[i]] - 1] = array[i];
		result_array[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = counting_array[i];
	}
	free(counting_array);
	free(result_array);
}
