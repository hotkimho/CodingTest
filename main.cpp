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

int main() {    
    int A[101];
    int B[101];
    int C[101];
    int n, n2;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cin >> n2;
    for (int i = 0; i < n2; i++)
        cin >> B[i];
    selection_sort()
    
}