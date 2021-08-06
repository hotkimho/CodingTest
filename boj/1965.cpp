#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;

int arr[10010];
int dp[10010];
int box(int n)
{
	int c = 0;
	int result = 0;
	
	for(int i=0; i<n; i++)
	{
		dp[i] = 1;
		for(int j=0; j<i; j++)
		{
			if(arr[i] > arr[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		if (c < dp[i])
			c = dp[i];
	}
	return c;
}

int main()
{
	int n;

	scanf("%d", &n);

	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	cout<<box(n);
	return 0;
}
