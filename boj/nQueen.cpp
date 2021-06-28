#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int c = 0;

int  isPromising(int *arr, int i)
{
	for (int j = 1; j < i; j++)
	{
		if (arr[j] == arr[i])
			return 0;
		else if (i - j == abs(arr[i] - arr[j]))
			return 0;
	}
	return 1;
}

void nQueen(int *arr, int i,int N)
{
	if (i > N)
	{
		c++;
		return ;
	}
	else
	{
		for (int j=1; j<=N; j++)
		{
			arr[i] = j;
			if (isPromising(arr, i))
				nQueen(arr, i + 1, N);
		}
	}
	return ;
}
int main()
{
	int N;
	int arr[16];

	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		arr[i] = 0;
	nQueen(arr, 1, N);
	printf("%d", c);
}

