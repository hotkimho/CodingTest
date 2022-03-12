#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

int n;
int sumOfSlice(int *arr, int H)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] - H > 0)
			sum = sum + arr[i] - H;
	}
	return sum;
}

int binary_search(int *arr, int target, int start, int end)
{
	if (start > end)
		return -1;
 
	int mid = (start + end) / 2;
	int sum = sumOfSlice(arr, mid);
	if (sum == target)
		return mid;
	if (sum > target)
		start = mid + 1;
	else
		end = mid - 1;
	return binary_search(arr, target, start, end);
}

int main()
{
	int arr[1000001];
	int k;
	int max = 0;
	freopen("input.txt", "r", stdin);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	
	cout << binary_search(arr, k, 0, max);
	
	
}
