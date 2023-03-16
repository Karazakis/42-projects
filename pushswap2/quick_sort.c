#include "push_swap.h"
void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int partition(int *arr, int low, int high)
{
	int pivot;
	int i;
	int j;

	i = (low - 1);
	pivot = arr[high];
	j = low;
	while(j <= high - 1) 
	{
		if (arr[j] < pivot) 
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int *arr, int low, int high)
{
	int pi;
	if (low < high) 
	{
		pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
