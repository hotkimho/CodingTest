#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;

int arr[10001];
int dp[10001];



//4
//3 5 15 16
//d[1] = 3
//d[2] = dp[2-1] + dp[1] or arr[2]
//d[3] = dp[3-1] + dp[1] or arr[3]
//d[4] = dp[4-1] + dp[1] or arr[4]
int main()
{
	int n, p;

	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);
	
	dp[1] = arr[1];

	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<i; j++)
		{
			dp[i] = max(dp[i], dp[j] + arr[i-j]);
		}
		dp[i] = max(dp[i], arr[i]);
	}

	cout<<dp[n];
	return 0;
}
