#ifndef _HASH_SET_MAP_H_
#define _HASH_SET_MAP_H_

#define HASH_SIZE 10

struct data_item {
	int data;
	int key;
};

struct hash_set {

};

struct hash_map {

};

void hash_set_insert();
void hash_map_insert(int key, int value);
void hash_set_find();
struct data_item hash_map_find(int key);
struct data_item * hash_map_delete(struct data_item * deleted);

#endif

