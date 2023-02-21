#include "sort.h"

/**
  * bubble_sort - sorts an array of integers in ascending order
  * @array: array to be printed
  * @size: number of elements in the array
  */

void bubble_sort(int *array, size_t size)
{
	int holder;
	size_t i = 0, t = size;

	if (array == NULL)
		return;
	for (t = size; t > 0; t--)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				holder = array[i];
				array[i] = array[i + 1];
				array[i + 1] = holder;
				print_array(array, size);
			}
		}
	}
}
