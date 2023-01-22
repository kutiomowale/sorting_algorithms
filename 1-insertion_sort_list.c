#include "sort.h"

/**
  * swap - A function that swaps two nodes of a doubly linked list
  *
  * @b: first node
  * @c: second node(b->next)
  */
void swap(listint_t *b, listint_t *c)
{
	listint_t *a;
	listint_t *d;

	if (!b || !c)
		return;
	a = b->prev;
	d = c->next;
	b->next = d;
	b->prev = c;
	c->prev = a;
	c->next = b;
	if (a)
		a->next = c;
	if (d)
		d->prev = b;
}

/**
  * insertion_sort_list - A function that sorts a doubly linked
  * list of integers in ascending order using the Insertion sort algorithm
  *
  * @list: A pointer pointing to a pointer pointing
  * to the first element of the doubly linked list of type listint_t
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *right; /* traverses the list towards the right  */
	listint_t *left; /* traverses the list towards the left */
	listint_t *temp;

	if (!list || !(*list))
		return;
	right = *list;
	while (right->next)
	{
		if (right->n > right->next->n)
		{
			left = right->next;
			if (!(right->prev))
				*list = left;
			swap(right, left);
			print_list(*list);
			while (left->prev)
			{
				if (left->n < left->prev->n)
				{
					temp = left->prev;
					if (!(temp->prev))
						*list = left;
					swap(temp, left);
					print_list(*list);
				}
				else
					break;
			}
		}
		else
			right = right->next;
	}
}
