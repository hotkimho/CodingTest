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


//  1 2 3 4 5 6 7 8 9 10
//1 1 1 1 1 1 1 1 1 1 1
//2 0 2 2 3 3 4 
//5
//d 1 2 2 1 1 1 1 1 1 1
int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=k; j++)
		{
			if ( arr[i] > j)
				continue;
			else if(arr[i] == j)
			{
				dp[j]++;
			}
			else if(arr[i] < j)
			{
				dp[j] = dp[j] + dp[j-arr[i]]; 
			}
		}
	}
	cout<<dp[k];
	return 0;
}
