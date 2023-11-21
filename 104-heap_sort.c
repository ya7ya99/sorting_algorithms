#include "sort.h"

/**
 * heapify - Adjusts the heap to maintain the heap property
 * @array: The array to be sorted as a heap
 * @size: The size of the heap
 * @i: The index of the root of the subtree to heapify
 * @n: The size of the array (used for printing)
 */
void heapify(int *array, size_t size, size_t i, size_t n)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;
	int temp;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;

		print_array(array, n);
		heapify(array, size, largest, n);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	size_t i;

	if (!array || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

