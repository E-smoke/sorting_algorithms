#include "sort.h"
/**
 * gap_sort - insertion sort with gap
 * @array: 1p
 * @size: 2p
 * @gap: 3p
 */
void gap_sort(int *array, size_t size, int gap)
{
int i, j, k, c, temp;
i = 0;
for (j = gap; j < (int)(size); ++j)
{
if (array[i] > array[j])
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
c = i;
k = i - gap;
while (k >= 0 && array[k] > array[c])
{
temp = array[k];
array[k] = array[c];
array[c] = temp;
c = k;
k -= gap;
}
}
++i;
}
}
/**
 * shell_sort - implements shell sort
 * @array: 1p
 * @size: 2p
 */
void shell_sort(int *array, size_t size)
{
int gap, check;
if (array == NULL)
{
return;
}
gap = 1;
while (gap < (int)size / 3)
{
gap = gap * 3 + 1;
}
check = gap;
for (gap += 0; gap >= 1; gap = ((gap - 1) / 3))
{
if (size >= 3)
{
gap_sort(array, size, gap);
print_array(array, size);
}
else
{
gap_sort(array, size, gap);
if (check != gap)
{
print_array(array, size);
}
}
}
}
