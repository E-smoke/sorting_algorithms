#include "sort.h"
/**
 * init - to initialize so that the function wont exceed 40 lines
 * @left: 1p
 * @right: 2p
 */
void init(listint_t **left, listint_t **right)
{
*left = NULL;
*right = NULL;
}
/**
 * swap - swaps two elements
 * @left: 1p
 * @right: 2p
 */
void swap(listint_t *left, listint_t *right)
{
if (left->prev != NULL)
{
(left->prev)->next = right;
}
if (right->next != NULL)
{
(right->next)->prev = left;
}
left->next = right->next;
right->next = left;
right->prev = left->prev;
left->prev = right;
}
/**
 * cocktail_sort_list - implements cocktail shaker sort
 * @list: p
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *current, *left, *right;
if (list == NULL || *list == NULL)
{
return; }
init(&left, &right);
current = *list;
while (1)
{
while (current->next != right)
{
if (current->n > (current->next)->n)
{
swap(current, current->next);
if ((current->prev)->prev == NULL)
{
*list = current->prev; }
print_list(*list);
continue; }
current = current->next; }
right = current;
current = current->prev;
if (current == left)
{
return; }
while (current->prev != left)
{
if (current->n < (current->prev)->n)
{
swap(current->prev, current);
if (current->prev == NULL)
{
*list = current; }
print_list(*list);
continue; }
current = current->prev; }
left = current;
current = current->next;
if (current == right)
{
return; }}}
