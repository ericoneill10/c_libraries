#include "sorts.h"
#include <stdio.h>

void merge_sort(int arr[], int size)
{
	// i, j are the first and last indices of the array
	int i, j;
	i = 0;
	j = size - 1;

	merge_sort_helper(arr, i, j);

}
void merge_sort_helper(int arr[], int i, int j)
{

	int mid = (i + j) / 2;
	if (i < j)
	{
		merge_sort_helper(arr, i, mid);
		merge_sort_helper(arr, mid + 1, j);
		merge(arr, i, mid, mid+1, j);
	}
}
void merge(int arr[], int i1, int j1, int i2, int j2)
{
	int temp[10000];
	int k = 0;
	int i = i1;
	int j = i2;

	while (i <= j1 && j <= j2)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}

	// copy over any remaining values
	while (i <= j1)
	{
		temp[k++] = arr[i++];
	}
	while (j <= j2)
	{
		temp[k++] = arr[j++];
	}

	//copy merged arrays back into original
	for (i = i1, j = 0; i <= j2; i++, j++)
	{
		arr[i] = temp[j];
	}
}
void quick_sort(int arr[], int l, int u)
{
	int final_partition_index;
	if (l < u)
	{
		final_partition_index = quick_sort_partition(arr, l, u);
		quick_sort(arr, l, final_partition_index-1);
		quick_sort(arr, final_partition_index + 1, u);

	}
}

int quick_sort_partition(int arr[], int l, int u)
{
	int partition_index = (l + u) / 2;
	int l1, u1;
	l1 = l;
	u1 = u;
	
}

void print_list(int arr[], int size)
{
	printf("List: \n");
	for (int i = 0; i < size; i++)
	{
		printf("%i, ", arr[i]);
	}
	printf("\n\n");
}

void print_sublist(int arr[], int size, int from, int to)
{
	if (from < 0 || to >= size)
	{
		printf("out of bounds\n");
		return;
	}
	for (int i = from; i <= to; i++)
	{
		printf("%i, ", arr[i]);
	}
	printf("\n");
}