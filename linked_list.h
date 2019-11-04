#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list_node {
	int data;
	struct list_node *next;
	struct list_node *prev;
};

struct linked_list {
	int size;
	struct list_node *head;
	struct list_node *tail;
};


void init_list(struct linked_list * ll);
void init_node(struct list_node * ln, int value);
void add_node(struct linked_list * ll, struct list_node * ln);
// returns linked_list size
void print_linked_list(struct linked_list * ll);
struct list_node * remove_node(struct linked_list * ll, int value);
#endif