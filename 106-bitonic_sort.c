#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two values in ascending or descending order.
 * @arr: The array.
 * @index1: Index of the first item.
 * @index2: Index of the second item.
 * @order: 1 for ascending order, 0 for descending order.
 */
void swap(int arr[], int index1, int index2, int order)
{
	int temp;

	if (order == (arr[index1] > arr[index2]))
	{
		temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
}

/**
 * merge - Recursively sort bitonic sequences in both orders.
 * @arr: The array.
 * @low: Index of the first element.
 * @num_element: Number of elements to merge.
 * @order: 1 for ascending order, 0 for descending order.
 */
void merge(int arr[], int low, int num_element, int order)
{
	int mid, i;

	if (num_element > 1)
	{
		mid = num_element / 2;
		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}

/**
 * bitonicsort - Implement the bitonic sort algorithm.
 * @arr: The array.
 * @low: Index of the first element.
 * @num_element: Number of elements to sort.
 * @order: 1 for ascending order, 0 for descending order.
 * @size: The length of the array.
 */
void bitonicsort(int arr[], int low, int num_element, int order, int size)
{
	int mid;

	if (num_element > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", num_element, size);
			print_array(&arr[low], num_element);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", num_element, size);
			print_array(&arr[low], num_element);
		}
		mid = num_element / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, num_element, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", num_element, size);
			print_array(&arr[low], num_element);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", num_element, size);
			print_array(&arr[low], num_element);
		}
	}
}

/**
 * bitonic_sort - Prepare the terrain for the bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The length of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
