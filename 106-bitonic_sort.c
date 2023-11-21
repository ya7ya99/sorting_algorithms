#include "sort.h"

/**
 * bitonic_swap - swaps two ints.
 * @a: the first int.
 * @b: the second.
 * Return: Nothing (void).
*/
void bitonic_swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Sorts a bitonic sequence inside an array.
 * @array: array of ints.
 * @size: the size of the array.
 * @start: the starting index.
 * @sq: the size of the sequence.
 * @direction: 'U' for UP and 'D' for DOWN
 * Return: nothing (void).
*/
void bitonic_merge(int *array, size_t size, size_t start,
									 size_t sq, char direction)
{
	size_t i, jump = sq / 2;

	if (sq <= 1)
	{
		return;
	}
	i = start;
	do {
		if ((direction == 'U' && array[i] > array[i + jump]) ||
				(direction == 'D' && array[i] < array[i + jump]))
		{
			bitonic_swap(array + i, array + i + jump);
		}
		i++;
	} while (i < start + jump);

	bitonic_merge(array, size, start, jump, direction);
	bitonic_merge(array, size, start + jump, jump, direction);

}

/**
 * bitonic_sequence - converts an array into bitonic sequence.
 * @array: array of int.
 * @size: size of the array.
 * @start: the starting index.
 * @sq: the size of a block of the building.
 * @direction: the direction to sort.
 * Return: Nothing (void).
*/
void bitonic_sequence(int *array, size_t size,
											size_t start, size_t sq, char direction)
{
	size_t c = sq / 2;

	if (sq <= 1)
	{
		return;
	}
	printf("Merging [%lu/%lu] (%s):\n",
			sq, size, (direction == 'U') ? "UP" : "DOWN");
	print_array(array + start, sq);

	bitonic_sequence(array, size, start, c, 'U');
	bitonic_sequence(array, size, start + c, c, 'D');
	bitonic_merge(array, size, start, sq, direction);

	printf("Result [%lu/%lu] (%s):\n",
				 sq, size, (direction == 'U') ? "UP" : "DOWN");
	print_array(array + start, sq);
}

/**
 * bitonic_sort -  sorts an array of integers in ascending order using the
 * Bitonic sort algorithm.
 * @array: array of int.
 * @size: size of the array.
 * Return: Nothing (void).
 *
*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, 'U');
}
