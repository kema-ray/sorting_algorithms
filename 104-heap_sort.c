#include "sort.h"

/**
  * swap - function that swaps two values
  * @element_a: first value
  * @element_b: second value
  */
void swap(int *element_a, int *element_b)
{
	int temp;

	temp = *element_b;
	*element_b = *element_a;
	*element_a = temp;
}

/**
 * heap_sort - Sorting array using heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: 0
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2; i >= 0; i--)
		sort_heap(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[i], &array[0]);
		if (i != 0)
			print_array(array, size);
		sort_heap(array, i, 0, size);
	}
}

/**
 * sort_heap - function to sort binary tree
 * @array: array to be sorted as binary tree
 * @end: Last node in binary tree
 * @start: First node of binary tree
 * @size: Size of the array to sort
 * Return: 0
 */
void sort_heap(int *array, int end, int start, size_t size)
{
	int max = start;
	int left = 2 * start + 1;
	int right = 2 * start + 2;

	if (!array || size < 2)
		return;

	if (left < end && array[left] > array[max])
		max = left;

	if (right < end && array[right] > array[max])
		max = right;

	if (start != max)
	{
		swap(&array[start], &array[max]);
		print_array(array, size);
		sort_heap(array, end, max, size);
	}
}
