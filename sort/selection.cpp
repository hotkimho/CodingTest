#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

//Ascending
void selection_sort(int *arr, int size)
{
    int minIdx;

	for (int i = 0; i < size - 1; i++)
	{
		minIdx = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}
		if (i != minIdx)
			swap(&arr[i], &arr[minIdx]);
	}
}