#include "sort.h"
#include <stdio.h>

/**
 * getMax - Get the max value in arr[].
 * @arr: The array.
 * @n: The size of the array.
 *
 * Return: The max value.
 */
int getMax(int *arr, int n)
{
	int i, max = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
 * countSort - Perform counting sort of arr[] based on the digit represented by exp.
 * @arr: The array to sort.
 * @n: The size of the array.
 * @exp: The exponent (10^i) for the current digit.
 * @output: The array to save the temporary values during sorting.
 */
void countSort(int *arr, size_t n, int exp, int *output)
{
	int i;
	int count[10] = {0};

	/* Store count of occurrences in count[] */
	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;

	/* Change count[i] so that count[i] now contains the actual position of this digit in output[] */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	/* Copy the output array to arr[], so that arr[] now contains sorted numbers according to the current digit */
	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];
	/* print_array(arr, n); */
}

/**
 * radix_sort - Sort an array of integers using Radix Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	/* Find the maximum number to determine the number of digits */
	int exp, max = 0;
	int *output = NULL; /* output array should be of size n (size) */

	if (array == NULL || size < 2)
		return;

	max = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;
	/*
	 * Do counting sort for every digit. Note that instead
	 * of passing the digit number, exp is passed. exp is 10^i
	 * where i is the current digit number.
	 */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
