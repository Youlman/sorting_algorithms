#include "sort.h"

#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
* selection_sort - sorts an array of integers in ascending
*		order using the selection sort algorithm
*
* @array: The array to be sorted
* @size: The size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, j_min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		j_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[j_min])
			{
				j_min = j;
			}
		}
		if (j_min != i)
		{
			swap_ints(array + i, array + j_min);
			print_array(array, size);
		}
	}
}

