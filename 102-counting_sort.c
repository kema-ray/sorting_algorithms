#include "sort.h"

/**
 * array_max - array max
 * @array: array
 * @size: size of the array
 * Return: max
 */
int array_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort - sorts an array with the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *arr, *tmp, max, num;
	size_t i;

	if (size < 2 || !array)
		return;
	max = array_max(array, size);

	arr = malloc(sizeof(size_t) * (max + 1));
	tmp = malloc(sizeof(int) * size);

	for (i = 0; (int)i <= max; i++)
		arr[i] = 0;
	for (i = 0; i < size; i++)
	{
		num = array[i];
		arr[num] += 1;
	}
	for (i = 1; (int)i <= max; i++)
		arr[i] += arr[i - 1];
	print_array(arr, max + 1);
	for (i = 0; i < size; i++)
	{
		tmp[arr[array[i]] - 1] = array[i];
		arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = tmp[i];

	free(tmp);
	free(arr);
}
