#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		unsigned int x = i;
		int aux = array[i];

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < aux)
				aux = array[j], x = j;
		}
		if (x != i)
		{
			array[x] = array[i];
			array[i] = aux;
			print_array(array, size);
		}
	}
}
