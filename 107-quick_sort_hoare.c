#include "sort.h"

/**
 * swap - Swap the positions of two elements in an array.
 * @array: The array.
 * @index1: Index of the first element.
 * @index2: Index of the second element.
 */
void swap(int *array, ssize_t index1, ssize_t index2)
{
	int tmp;

	tmp = array[index1];
	array[index1] = array[index2];
	array[index2] = tmp;
}

/**
 * hoare_partition - Implement the Hoare partition sorting scheme.
 * @array: The array to be sorted.
 * @first: Index of the first element.
 * @last: Index of the last element.
 * @size: The size of the array.
 * Return: The position of the last element sorted.
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int present = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{
		do {
			present++;
		} while (array[present] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);

		if (present >= finder)
			return (present);

		swap(array, present, finder);
		print_array(array, size);
	}
}

/**
 * recursive - Implement the quicksort algorithm recursively.
 * @array: The array to be sorted.
 * @first: Index of the first element.
 * @last: Index of the last element.
 * @size: The size of the array.
 */
void recursive(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		recursive(array, first, position - 1, size);
		recursive(array, position, last, size);
	}
}

/**
 * quick_sort_hoare - Prepare the terrain for the Hoare quicksort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	recursive(array, 0, size - 1, size);
}
