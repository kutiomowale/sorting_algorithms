#include "sort.h"

/**
  * selection_sort - A funtion that sorts an array of integers
  * using the Selection sort algorithm
  *
  * @array: The array to be sorted
  * @size: The number of elements in @array
  */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min;	/* Index of the smallest integer on each array pass */
	size_t temp;	/* Used when swapping integers */

	if (!array || size <= 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i != min)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
