#include "sort.h"


void print_array(const int *array, size_t size);

/**
* bubble_sort - sorts an array of integers in ascending
*		order using the Bubble sort algorithm
*
* @array: The array to be sorted
* @size: The size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t j;
	int temp;
	bool swaped = false;

	if (array == NULL || size < 2)
		return;

	while (swaped == false)
	{
		swaped = true;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swaped = false;
			}
		}
	}
}

