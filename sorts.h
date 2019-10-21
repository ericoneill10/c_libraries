#ifndef _SORTS_H_
#define _SORTS_H_

#define TEST_SIZE 16



void merge_sort(int arr[], int size);
void merge_sort_helper(int arr[], int i, int j);
void merge(int arr[], int i1, int j1, int i2, int j2);
void quick_sort(int arr[], int l, int u);
int quick_sort_partition(int arr[], int l, int u);
void print_list(int arr[], int size);
void print_sublist(int arr[], int size, int from, int to);

#endif // _SORTS_H_

