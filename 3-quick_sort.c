#include "sort.h"

void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: the size of the array
 * @lower_index: The starting index of the subset to order.
 * @upper_index: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int lower_index, int upper_index)
{
	int *pivot, i, index;

	index = lower_index;
	pivot = array + upper_index;
	for (i = lower_index; i < upper_index; i++)
	{
		if (array[i] < *pivot)
		{
			if (index < i)
			{
				swap(&array[i], &array[index]);
				print_array(array, size);
			}
			index++;
		}
	}
	if (array[index] > *pivot)
	{
		swap(pivot, &array[index]);
		print_array(array, size);
	}
	return (index);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @lower_index: The starting index of the array partition to order.
 * @upper_index: The ending index of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int lower_index, int upper_index)
{
	int pindex;

	if (lower_index < upper_index)
	{
		pindex = lomuto_partition(array, size, lower_index, upper_index);
		lomuto_sort(array, size, lower_index, pindex - 1);
		lomuto_sort(array, size, pindex + 1, upper_index);
	}
}

/**
* quick_sort - sorts an array of integers in ascending
*		order using the quick sort algorithm
*
* @array: The array to be sorted
* @size: the size of the array.
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
