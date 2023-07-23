#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 **/
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * maxHeapify - Rearranges the elements of an array to maintain
 *              the max-heap property.
 * @array: The array to be heapified.
 * @size: Size of the array for printing.
 * @idx: Index of the current node to be heapified.
 * @n: Size of the heap to be considered.
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
    int biggest = idx;          /** Initialize biggest as root*/
    int left = 2 * idx + 1;     /** left = (idx << 1) + 1 */
    int right = 2 * idx + 2;    /** right = (idx + 1) << 1 */

    /** Check if left child of root exists and is greater than root*/
    if (left < (int)n && array[left] > array[biggest])
        biggest = left;

    /**Check if right child of root exists and is greater than the biggest */
/** so far */
    if (right < (int)n && array[right] > array[biggest])
        biggest = right;

    /** Change root, if needed */
    if (biggest != idx)
    {
        swap(&array[idx], &array[biggest]);
        print_array(array, size);
        maxHeapify(array, size, biggest, n);
    }
}

/**
 * heap_sort - Sorts an array using the Heap Sort algorithm.
 * @array: The array to be sorted.
 * @size: Size of the array.
 **/
void heap_sort(int *array, size_t size)
{
    int i;

    /** Build max heap */
    if (array == NULL || size < 2)
        return;

    for (i = (size - 2) / 2; i >= 0; --i)
        maxHeapify(array, size, i, size);

    /** Heap sort */
    for (i = (size - 1); i > 0; --i)
    {
        /** Swap the biggest element (root) with the last element */
/** of the heap */
        swap(&array[0], &array[i]);
        print_array(array, size);

        /** Heapify the new root */
        maxHeapify(array, size, 0, i);
    }
}
