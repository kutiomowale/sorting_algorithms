#include "sort.h"
/**
  * bubble_sort - A function that sorts an array of integers
  * in ascending order using the Bubble sort algorithm
  *
  * @array: The array to be sorted
  * @size: The size of the array
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap_done;

	if ((array && size) || size > 0)
	{
		swap_done = 0;
		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					print_array(array, size);
					swap_done = 1;
				}
			}
			if (swap_done == 0)
				break;
		}
	}
}
