#include "sort.h"
/**
 * insertion_sort_list - implements insertion sort algorithm
 * @list: the double linked list
 */
void insertion_sort_list(listint_t **list)
{
int i, len;
listint_t *curr, *start;
curr = *list;
len = 0;
while (curr != NULL)
{
++len;
curr = curr->next;
}
if (len == 1)
{
return; }
start = (*list)->next;
for (i = 1; i < len; ++i)
{
curr = start;
start = start->next;
while (curr->prev != NULL && curr->n < ((curr->prev)->n))
{
if (curr->next != NULL)
{
(curr->next)->prev = curr->prev; }
if ((curr->prev)->prev != NULL)
{
((curr->prev)->prev)->next = curr; }
(curr->prev)->next = curr->next;
curr->next = curr->prev;
curr->prev = (curr->prev)->prev;
(curr->next)->prev = curr;
if (curr->prev == NULL)
{
*list = curr; }
print_list(*list); }}}
