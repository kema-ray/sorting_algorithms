#include "sort.h"

/**
  * sort_merge - sorts an array
  * @arr: array to be sorted
  * @tmp: array for holding sorted elements temporary
  * @size: size of the array
  */

void sort_merge(int *arr, int *tmp, size_t size)
{
	size_t divide = size / 2, m = 0, n = 0, p;

	if (size < 2)
		return;
	sort_merge(arr, tmp, divide);
	sort_merge(arr + divide, tmp + divide, size - divide);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr, divide);
	printf("[right]: ");
	print_array(arr + divide, size - divide);

	for (p = 0; p < size; p++)

		if (n >= size - divide || (m < divide && arr[m] < (arr + divide)[n]))
		{
			tmp[p] = arr[m];
			m++;
		}
		else
		{
			tmp[p] = (arr + divide)[n];
			n++;
		}
	for (p = 0; p < size; p++)
		arr[p] = tmp[p];
	printf("[Done]: ");
	print_array(arr, size);
}

/**
  * merge_sort - sorts an array of integers in ascending order
  * @array: array to be sorted
  * @size: size of the array
  */

void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(*tmp) * size);
	if (!tmp)
		return;

	sort_merge(array, tmp, size);
	free(tmp);
}
