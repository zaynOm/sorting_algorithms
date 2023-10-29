#include "sort.h"

/**
 * selection_sort - sorts an array of ints using the Selection sort algorithm.
 * @array: array to sort.
 * @size: size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t  j, i;
	int small, tmp;

	if (!array || size < 2)
		return;

	for (i = 0; i + 1 < size; i++)
	{
		small = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[small])
				small = j;
		}
		if ((int)i != small)
		{
			tmp = array[i];
			array[i] = array[small];
			array[small] = tmp;
			print_array(array, size);
		}
	}
}
