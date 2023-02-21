#include "sort.h"

/**
  * shell_sort - sorts an array of integers in ascending order using the 
  * Shell sort algorithm, using the Knuth sequence
  * @array: array to sort
  * @size: size of the array
  */

void shell_sort(int *array, size_t size)
{
	int m, n, temp, tmp = 1;

	while (tmp < ((int)(size)))
	{
			tmp = (3 * tmp) + 1;
	}
	for (tmp = (tmp - 1) / 3; tmp > 0; tmp = (tmp - 1) / 3)
	{
		for (m = tmp; m < (int)size; m += 1)
		{
			temp = array[m];

			for (n = m; n >= tmp && array[n - tmp] > temp; n -= tmp)
				array[n] = array[n - tmp];
			array[n] = temp;
		}
		print_array(array, size);
	}
}
