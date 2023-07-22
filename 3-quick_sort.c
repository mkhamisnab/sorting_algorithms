#include "sort.h"
/**
 * swap - sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @i: left element
 * @j: right element
 * @size: size of array
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 * partition - sort array partition
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 * Return: pivot sorted
 */
int partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 * recursive - quick_sort core
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 */
void recursive(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = partition(array, first, last, size);

		recursive(array, first, position - 1, size);
		recursive(array, position + 1, last, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	recursive(array, 0, size - 1, size);
}
