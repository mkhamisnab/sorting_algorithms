#include "sort.h"
#include <stdio.h>

/**
 * _calloc - Allocates memory for an array using calloc.
 * @nmemb: Number of elements to allocate.
 * @size: Size of each element in bytes.
 *
 * Return: Pointer to the allocated memory, or NULL if it fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		p[i] = 0;

	return (p);
}

/**
 * merge - Merge two sorted sub-arrays into one sorted array.
 * @arr: Original array containing the two sub-arrays.
 * @tmp: Temporary array used in the merging process.
 * @begin: Index of the first element of the first sub-array.
 * @centre: Index of the last element of the first sub-array.
 * @end: Index of the last element of the second sub-array.
 */
void merge(int *arr, int *tmp, int begin, int centre, int end)
{
	int size_left = centre - begin + 1;
	int size_right = end - centre;
	int *array_left, *array_right;
	int left, right, i = 0;

	array_left = &tmp[0];
	array_right = &tmp[size_right];

	/** Copy data to temporary arrays*/
	for (left = 0; left < size_left; left++)
		array_left[left] = arr[begin + left];
	for (right = 0; right < size_right; right++)
		array_right[right] = arr[centre + 1 + right];

	left = 0, right = 0, i = begin;

	/** Merge the two temporary arrays back into the main array*/
	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			arr[i] = array_left[left], left++;
		else
			arr[i] = array_right[right], right++;
		i++;
	}

	/** Merge any remaining elements from the left and right arrays*/
	while (left < size_left)
		arr[i] = array_left[left], left++, i++;
	while (right < size_right)
		arr[i] = array_right[right], right++, i++;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[begin], left + right);
}

/**
 * mergesort - Recursive function to sort an array using Merge Sort.
 * @array: Array of integers to be sorted.
 * @tmp: Temporary array used in the merging process.
 * @begin: begining index of the sub-array to be sorted.
 * @end: Ending index of the sub-array to be sorted.
 */
void mergesort(int *array, int *tmp, int begin, int end)
{
	int centre;

	centre = (begin + end) / 2;
	if ((begin + end) % 2 == 0)
		centre--;

	if (centre >= begin)
	{
		mergesort(array, tmp, begin, centre);
		mergesort(array, tmp, centre + 1, end);
		merge(array, tmp, begin, centre, end);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge Sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = _calloc(size, sizeof(int));
	if (!tmp)
		return;

	mergesort(array, tmp, 0, size - 1);
	free(tmp);
}
