#include "sort.h"
#include <stdio.h>

/**
 * _calloc - Allocates memory for an array using calloc.
 * @nmemb: Number of elements to allocate.
 * @size: Size of each element.
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
 * counting_sort - Implements the counting sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int index, maxm = 0, *counter = NULL, *tmp = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum number */
	for (i = 0; i < size; i++)
		if (array[i] > maxm)
			maxm = array[i];

	counter = _calloc(maxm + 1, sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));

	/* Count the occurrences of each element in the array */
	for (i = 0; i < size; i++)
		counter[array[i]]++;

	/* Compute the cumulative sum of the counts */
	for (index = 1; index <= maxm; index++)
		counter[index] += counter[index - 1];

	print_array(counter, maxm + 1);

	/* Create the sorted array using the counts */
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	/* Copy the sorted array back into the original array */
	for (i = 0; i < size; i++)
		array[i] = tmp[i];

	free(tmp);
	free(counter);
}
