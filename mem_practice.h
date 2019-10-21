#ifndef MEM_PRACTICE_H
#define MEM_PRACTICE_H
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"
typedef struct alloc_node {
	struct list_node node;
	size_t size;
	char * block;
	bool free;
};
void init_block(char * head_node, uint32_t size);

char * mem_malloc(size_t size);

#endif
