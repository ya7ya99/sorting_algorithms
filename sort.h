#ifndef __SORT__
#define __SORT__
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void merge(int *array, int *left, int *right, size_t size_l, size_t size_r);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void swap(listint_t *a, listint_t *b);

int partition(int *array, int start, int end, size_t size);
void quicksort(int *array, int start, int end, size_t size);

void quick_sort_hoare(int *array, size_t size);
void quicksorthoare(int *array, int low, int high, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);

int find_max_value(int *array, size_t size);

void swap_node(listint_t **list, listint_t **a, listint_t **b, int is_ahead);

void bitonic_swap(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start,
									 size_t sq, char direction);
void bitonic_sequence(int *array, size_t size,
											size_t start, size_t sq, char direction);


void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int partition(int *array, int lo, int hi, size_t size);
void quick_s(int *array, int lo, int hi, size_t size);
void swap_root(int *array, size_t root, size_t hi, size_t size);

#endif /* __SORT__ */
