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
void insertion_sort(int *arr, int size)
{
    int key, j;

    for (int i = 1; i < size; i ++)
    {
        key = arr[i];
        j = i - 1;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = key;
    }
}