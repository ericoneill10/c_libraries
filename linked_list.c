#include "linked_list.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void init_list(struct linked_list * ll)
{
	ll->head = NULL;
	ll->tail = NULL;
	ll->size = 0;
}

void init_node(struct list_node * ln, int n)
{
	ln->next = NULL;
	ln->prev = NULL;
	ln->data = n;
}

void add_node(struct linked_list * ll, struct list_node * ln)
{

	if (ll -> size == 0) {
		ll -> head = ln;
		ll -> tail = ln;
	}
	else
	{
		ll -> tail -> next = ln;
		ln -> prev = ll -> tail;
		ll -> tail = ln;
	}
	ll -> size++;
}

void print_linked_list(struct linked_list * ll)
{
	if (ll->size == 0)
	{
		printf("list empty\n");
	}
	else
	{
		struct list_node * temp = ll->head;
		while (temp != NULL)
		{
			printf("| %i | -> ", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

struct list_node * remove_node(struct linked_list * ll, int value)
{
	if (ll -> size > 0)
	{
		struct list_node * temp = ll->head;
		while (temp != NULL)
		{
			if (temp->data == value)
			{
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				return temp;
			}
			temp = temp->next;
		}
	}
	return NULL;
}


