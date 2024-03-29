#ifndef SORT
#define SORT
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, size_t size, int l, int r);
void quick_sort_recursive(int *array, size_t size, int l, int r);
void gap_sort(int *array, size_t size, int gap);
void shell_sort(int *array, size_t size);
void swap(listint_t *left, listint_t *right);
void cocktail_sort_list(listint_t **list);
void init(listint_t **left, listint_t **right);
int *create_array(size_t size);
void init_to_zero(int *array, size_t size);
void copy(int *src, int *dest, size_t size);
void counting_sort(int *array, size_t size);
int *merge_sort1(int *array, size_t size, int *sptr);
void merge_sort(int *array, size_t size);
void copy1(int *src, int *desti, size_t size);
int hoare(int *ori_array, int *array, size_t size, size_t ori_size);
void quick_sort_hoare(int *array, size_t size);
void quick_sort_hoare1(int *oa, int *array, size_t size, size_t os);
#endif
