#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

//오름차순
void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > 0 && arr[j + 1] < 0)
                swap(&arr[j], &arr[j + 1]);
        }
    }
}