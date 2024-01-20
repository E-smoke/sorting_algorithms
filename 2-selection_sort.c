#include "sort.h"
/**
 * selection_sort -iplements selection sort
 * @array: 1p
 * @size: 2p
 */
void selection_sort(int *array, size_t size)
{
int i, j, min, idx;
i = 0;
while ((size_t)i < size)
{
j = i;
min = array[j];
idx = j;
while ((size_t) ++j < size)
{
if (min > array[j])
{
min = array[j];
idx = j;
}
}
if (i != idx)
{
array[idx] = array[i];
array[i] = min;
print_array(array, size);
}
++i;
}
}
