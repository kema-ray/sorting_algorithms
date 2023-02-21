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
  */
void quick_sort(int *array, size_t size)
