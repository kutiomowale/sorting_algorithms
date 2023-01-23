#include "sort.h"

/**
  * swap - Helper function that does the necessary swaps
  * for the shell_sort function
  *
  * @array: The array to be sorted
  * @j: Index to possibly swap
  * @n: @j + n is the index to possibly swap with @j
  * @i: To ensure swaps are within range
  * Description: This is an helper function to help refactor the shell_sort
  * function(Too many leading tabs)
  */
void swap(int *array, int j, int n, int i)
{
	int k, temp;

	if (!array)
		return;
	if (array[j] > array[j + n])
	{
		temp = array[j];
		array[j] = array[j + n];
		array[j + n] = temp;
		for (k = j; k > i; k = k - n)
		{
			if (array[k] < array[k - n])
			{
				temp = array[k];
				array[k] = array[k - n];
				array[k - n] = temp;
			}
		}
	}
}

/**
  * shell_sort - A function that sorts an array of integers in ascending order
  * using the Shell sort algorithm, using the Knuth sequence
  *
  * @array: The array to be sorted
  * @size: Number of elements in @array
  * Description: n+1 = n * 3 + 1
  * 1, 4, 13, 40, 121, ...
  * The array is displayed each time the interval is decreased
  */
void shell_sort(int *array, size_t size)
{
	int gap_max, n, i, j, len;

	if (!array || size < 2)
		return;
	len = (int) size;
	for (gap_max = 1; gap_max < len; gap_max = (gap_max * 3) + 1)
		;
	gap_max = (gap_max - 1) / 3;
	for (n = gap_max; n > 0; n = (n - 1) / 3)
	{
		if (n != gap_max)
			print_array(array, size);
		for (i = 0; i < n; i++)
		{
			for (j = i; (j + n) < len; j = j + n)
				swap(array, j, n, i);
		}
	}
	print_array(array, size);
}
