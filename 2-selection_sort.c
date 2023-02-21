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
  * selection_sort - sorts an array of integers in ascending order
  * @array: the array to be printed
  * @size: number of elements in the array
  */

void selection_sort(int *array, size_t size)
{
	unsigned int m, n, min_idx;

	if (!array)
		return;
	for (m = 0; m < size - 1; m++)
	{
		min_idx = m;
		for (n = m + 1; n < size; n++)
		{
			if (array[n] < array[min_idx])
				min_idx = n;
		}
		if (m != min_idx)
		{
			swap(&array[min_idx], &array[m]);
			print_array(array, size);
		}
	}
}
