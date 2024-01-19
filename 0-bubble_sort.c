#include "sort.h"
/**
 * bubble_sort - implements bubble sort algorithm
 * @array: 1p
 * @size: 2p
 */
void bubble_sort(int *array, size_t size)
{
size_t i;
size_t j;
size_t temp;
for (i = 0; i < size; ++i)
{
for (j = 0; j < (size - i - 1); ++j)
{
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
print_array(array, size);
}
}
}
}
