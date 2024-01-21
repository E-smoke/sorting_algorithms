#include "sort.h"
/**
 * create_array - creates array of integers
 * @size: p
 * Return: ptr to the array
 */
int *create_array(size_t size)
{
int *ptr;
ptr = (int *)malloc(sizeof(int) * size);
return (ptr);
}
/**
 * init_to_zero - initializes the array to zero
 * @array: 1p
 * @size: 2p
 */
void init_to_zero(int *array, size_t size)
{
int i;
for (i = 0; i < (int)size; ++i)
{
array[i] = 0;
}
}
/**
 * copy - implements copy
 * @src: 1p
 * @dest: 2p
 * @size: 3p
 */
void copy(int *src, int *dest, size_t size)
{
size_t i;
for (i = 0; i < size; ++i)
{
dest[i] = src[i];
}
}
/**
 * counting_sort - implements counting sort
 * @array: 1p
 * @size: 2p
 */
void counting_sort(int *array, size_t size)
{
int i, max, *ca, *na;
max = array[0];
for (i = 1; i < (int)size; ++i)
{
if (max < array[i])
{
max = array[i];
}
}
ca = create_array(max + 1);
init_to_zero(ca, max + 1);
for (i = 0; i < (int)size; ++i)
{
++ca[array[i]];
}
for (i = 1; i < max + 1; ++i)
{
ca[i] += ca[i -1];
}
print_array(ca, max + 1);
na = create_array(size);
for (i  = (size - 1); i >= 0; --i)
{
na[--ca[array[i]]] = array[i];
}
copy(na, array, size);
free(ca);
free(na);
}
