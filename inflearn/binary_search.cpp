#include <iostream>
#include <vector>
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

//정수
//정답이 항상 주어지는 경우
int binary_search(int *arr, int size, int key) {
    int start = 0, end = size - 1, mid;
    
    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] < key) 
            start = mid + 1;
        else if (arr[mid] > key)
            end = mid - 1;
        else 
            return mid + 1;
    }
    return -1;
}