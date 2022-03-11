#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int *arr, int start, int end)
{
	if (start > end) return;
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left < right)
	{
		while (arr[pivot] > arr[left])
			left++;
		while (arr[pivot] < arr[right])
			right--;
		if (left > right)
			swap(&arr[pivot], &arr[right]);
		else
			swap(&arr[left], &arr[right]);
	}
	quickSort(arr, start, right - 1);
	quickSort(arr, right + 1, end);
}

int main() 
{
	int arr[10001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	quickSort(arr, 0, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
