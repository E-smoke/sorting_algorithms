#include "sort.h"
/**
 * merge - merges two sorted array
 * @lptr: 1p
 * @rptr: 2p
 * @sptr: 3p
 * @size: 4p
 * Return: ptr to int
 */
int *merge(int *lptr, int *rptr, int *sptr, size_t size)
{
int i;
if (lptr[0] < rptr[0])
{
sptr[0] = lptr[0];
sptr[1] = rptr[0];
i = 1;
}
else
{
for (i = 0; i < (int)size; ++i)
{
if (lptr[0] > rptr[i])
{
sptr[i] = rptr[i];
continue;
}
sptr[i] = lptr[0];
break;
}
}
if (i == (int)size)
{
sptr[i] = lptr[0];
}
for (i += 0; i < (int)size; ++i)
{
sptr[i + 1] = rptr[i];
}
copy1(sptr, lptr, size);
return (sptr);
}
/**
 * merge_sort1 - implements merge sort
 * @array: 1p
 * @size: 2p
 * @sptr: 3ip
 * Return: ptr to int
 */
int *merge_sort1(int *array, size_t size, int *sptr)
{
int *lptr, *rptr;
if (size == 1)
{
return (array);
}
else
{
lptr = array;
rptr = array + 1;
merge_sort1(rptr, size - 1, sptr);
}
printf("Merging...\n");
printf("[left]: ");
print_array(rptr, size - 1);
printf("[right]: ");
print_array(lptr, 1);
merge(lptr, rptr, sptr, size);
printf("[Done]: ");
print_array(lptr, size);
return (sptr);
}
/**
 * merge_sort - implements merge sort
 * @array: 1p
 * @size: 2p
 */
void merge_sort(int *array, size_t size)
{
int *sptr;
sptr = (int *)malloc(sizeof(int) * size);
if (sptr == NULL)
{
return;
}
merge_sort1(array, size, sptr);
copy1(sptr, array, size);
free(sptr);
}
/**
 * copy1 - copies
 * @src: 1p
 * @dest: 2p
 * @size: 3p
 */
void copy1(int *src, int *dest, size_t size)
{
int i;
for (i = 0; i < (int)size; ++i)
{
dest[i] = src[i];
}
}
