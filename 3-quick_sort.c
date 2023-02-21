#include "sort.h"

/**
  * swap - function that swaps two values
  * @element_a: first value
  * @element_b: second value
  */
void swap(int *element_a, int *element_b)
{
	int temp;

	temp = *element_a;
	*element_a = *element_b;
	*element_b = temp;
}

/**
 * lomuto_split - Split the array and takes the last element as pivot
 * @array: Array
 * @first: first element
 * @last: The last element
 * @size: size
  */
int lomuto_split(int *array, int first, int last, size_t size)
{
	int tmp;
	int m = (first);
	int n;

	tmp = array[last];
	for (n = first; n < last; n++)
	{
		if (array[n] <= tmp)
		{
			swap(&array[m], &array[n]);

			if (m != n)
				print_array(array, size);
			m++;
		}
	}
	swap(&array[m], &array[last]);
	if (m != n)
		print_array(array, size);
	return (m);
}

/**
 * lomuto_quick_sort_array - Implement the quicksort algorithm
 * through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @first: The starting index of the array partition to order.
 * @last: The ending index of the array partition to order.
  */

void lomuto_quick_sort_array(int *array, int first, int last, size_t size)
{
	int tmp;

	if (first < last)
	{
		tmp = lomuto_split(array, first, last, size);
		lomuto_quick_sort_array(array, first, (tmp - 1), size);
		lomuto_quick_sort_array(array, (tmp + 1), last, size);
	}
}

/**
  * quick_sort - function that sorts an array of integers in ascending order
  * @array: array to be sorted
  * @size: size of the arrat to be sorted
  */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_quick_sort_array(array, 0, size - 1, size);
}
