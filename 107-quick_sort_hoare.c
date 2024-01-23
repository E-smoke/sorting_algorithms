#include "sort.h"
/**
 * hoare - implements hoare partition
 * @ori_array: 1p
 * @array: 2p
 * @size: 3p
 * @ori_size: 4p
 * Return: int
 */
int hoare(int *ori_array, int *array, size_t size, size_t ori_size)
{
int i, j, value, temp;
i = 0;
j = size - 1;
while (1)
{
while (i < (int)size && array[i] < array[size - 1] && i != j)
{
++i;
}
if (i == j)
{
temp = array[j];
array[j] = array[size - 1];
array[size - 1] = temp;
value = j;
break;
}
while (j > -1 && array[j] > array[size - 1] && i != j)
{
--j;
}
if (i == j)
{
temp = array[j + 1];
array[j + 1] = array[size - 1];
array[size - 1] = temp;
value = (j + 1);
break;
}
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(ori_array, ori_size);
}
return (value);
}
/**
 * quick_sort_hoare1 - implements quick sort using hoare partition
 * @oa: 1p
 * @array: 2p
 * @size: 3p
 * @os:4p
 */
void quick_sort_hoare1(int *oa, int *array, size_t size, size_t os)
{
int pi;
if (size <= 1)
{
return;
}
pi = hoare(oa, array, size, os);
quick_sort_hoare1(oa, array, pi, os);
quick_sort_hoare1(oa, array + pi + 1, size - pi - 1, os);
}
/**
 * quick_sort_hoare - encapsulates quick_sort_hoare1()
 * @array: 1p
 * @size: 2p
 */
void quick_sort_hoare(int *array, size_t size)
{
quick_sort_hoare1(array, array, size, size);
}
