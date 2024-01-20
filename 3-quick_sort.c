#include "sort.h"
/**
 * partition - implements partition
 * @array: 1p
 * @size: 2p
 * @l: 3p
 * @r: 4p
 * Return: integer
 */
int partition(int *array, size_t size, int l, int r)
{
int i, j, temp;
i = l - 1;
for (j = l; j < (r); ++j)
{
if (array[j] > array[r])
{
continue;
}
else
{
++i;
if (i != j)
{
temp = array[j];
array[j] = array[i];
array[i] = temp;
print_array(array, size);
}
}
}
if ((i + 1) != (r))
{
temp = array[i + 1];
array[i + 1] = array[r];
array[r] = temp;
print_array(array, size);
}
return (i + 1);
}
/**
 * quick_sort_recursive - implements quick sort
 * @array: 1p
 * @size: 2p
 * @l: 3p
 * @r: 4p
 */
void quick_sort_recursive(int *array, size_t size, int l, int r)
{
int p;
if (size == 0 || size == 1 || l >= r)
{
return;
}
p = partition(array, size, l, r);
quick_sort_recursive(array, size, l, p - 1);
quick_sort_recursive(array, size, p + 1, r);
}
/**
 * quick_sort - calls quick_sort_recursive to meet alx requiremens
 * @array: 1p
 * @size: 2p
 */
void quick_sort(int *array, size_t size)
{
quick_sort_recursive(array, size, 0, (int)(size - 1));
}
