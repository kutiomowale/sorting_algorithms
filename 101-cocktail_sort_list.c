#include "sort.h"

/**
  * swap - An helper function for the cocktail_sort_list function
  *
  * @b: First node
  * @c: Second node(@b->next)
  * @list: Double pointer to the head node
  *
  * Description: It swaps two nodes of a doubly linked list
  * and updates the pointer pointing to the head node pointer
  * when necessary (when @b is the head node)
  */
void swap(listint_t *b, listint_t *c, listint_t **list)
{
	listint_t *a;
	listint_t *d;

	if ((!b || !c) || !list)
		return;
	a = b->prev;
	d = c->next;
	b->next = d;
	b->prev = c;
	c->prev = a;
	c->next = b;
	if (a)
		a->next = c;
	if (!a)
		*list = c;
	if (d)
		d->prev = b;
}

/**
  * back_and_forth - An helper function for the cocktail_sort_list function
  *
  * @pass: A pointer that is used to traverse the doubly linked list
  * @start: A pointer that indicates where to start forward movement
  * @end: A pointer that indicates where to start backward movement
  * @list: A pointer pointing to a pointer pointing
  * to the first element of the doubly linked list of type listint_t
  * @swap_done: Used as a flag indicating swap or no swap
  */
void back_and_forth(listint_t *pass, listint_t *start,
	listint_t *end, listint_t **list, int swap_done)
{
	swap_done = 1;
	while (swap_done == 1)
	{
		swap_done = 0;
		pass = end;
		while (pass != start && pass->next != start)
		{
			if (pass->n < pass->prev->n)
			{
				swap(pass->prev, pass, list);
				if (end == pass)
					end = end->next;
				print_list(*list);
				swap_done = 1;
			}
			else
				pass = pass->prev;
		}
		if (pass == start)
			start = pass->next;
		if (swap_done == 0)
			break;
		swap_done = 0;
		pass = start;
		while (pass != end && pass->prev != end)
		{
			if (pass->n > pass->next->n)
			{
				swap(pass, pass->next, list);
				if (start == pass)
					start = start->prev;
				print_list(*list);
				swap_done = 1;
			}
			else
				pass = pass->next;
		}
		if (pass == end)
			end = pass->prev;
	}
}

/**
  * cocktail_sort_list - A function that sorts a doubly linked
  * list of integers in ascending order using the
  * Cocktail shaker sort algorithm
  *
  * @list: A pointer pointing to a pointer pointing
  * to the first element of the doubly linked list of type listint_t
  */
void cocktail_sort_list(listint_t **list)
{
	listint_t *pass, *start, *end;
	int swap_done;

	if (!list || !(*list))
		return;
	swap_done = 0;
	pass = *list;
	start = pass;
	while (pass->next)
	{
		if (pass->n > pass->next->n)
		{
			swap(pass, pass->next, list);
			if (start == pass)
				start = start->prev;
			print_list(*list);
			swap_done = 1;
		}
		else
			pass = pass->next;
	}
	end = pass->prev;
	if (swap_done == 0)
		return;
	back_and_forth(pass, start, end, list, swap_done);
}
