#include "sort.h"

/**
  * partition - A function that divides an array into two parts
  *
  * @array: The array to be partitioned
  * @low: Lowest index to consider
  * @high: Highest index to consider
  * @size: Number of elements in @array
  * Description: The Lomuto partition scheme is implemented
  * The initial pivot is always the last element of the
  * partition being sorted
  * Return: The new index of the pivot
  */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i = i + 1;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	i = i + 1;
	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
  * actual_quick_sort - A function that sorts an array of integers
  * in ascending order using the Quick sort algorithm
  *
  * @array: The array to be sorted
  * @low: Lowest index to consider
  * @high: Highest index to consider
  * @size: Number of elements in @array
  * Description: The Lomuto partition scheme is implemented
  * The pivot will initially be the last element of the partition being sorted
  */
void actual_quick_sort(int *array, int low, int high, size_t size)
{
	int p;

	if (low >= high || low < 0)
		return;
	p = partition(array, low, high, size);
	actual_quick_sort(array, low, p - 1, size); /* First partion */
	actual_quick_sort(array, p + 1, high, size); /* Second partion */
}

/**
  * quick_sort - A function that sorts an array of integers
  * in ascending order using the Quick sort algorithm
  *
  * @array: The array to be sorted
  * @size: The number of element in array
  * Description: The Lomuto partition scheme is implemented
  * The pivot is always be the last element of the partition being sorted
  */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	actual_quick_sort(array, 0, size - 1, size);
}
