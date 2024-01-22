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
i = 2;
}
else
{
for (i = 0; i < (int)size; ++i)
{
if (i < (int)(size - 1) && lptr[0] > rptr[i])
{
sptr[i] = rptr[i];
continue;
}
sptr[i] = lptr[0];
++i;
break;
}
}
for (i += 0; i < (int)size; ++i)
{
sptr[i] = rptr[i - 1];
}
copy(sptr, lptr, size);
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
rptr = merge_sort1(rptr, size - 1, sptr);
}
if (sptr == NULL)
{
return (NULL);
}
printf("Merging...\n");
printf("[left]: ");
print_array(lptr, 1);
printf("[right]: ");
print_array(rptr, size - 1);
sptr = merge(lptr, rptr, sptr, size);
printf("[Done]: ");
print_array(sptr, size);
return (lptr);
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
copy(sptr, array, size);
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
src[i] = dest[i];
}
}