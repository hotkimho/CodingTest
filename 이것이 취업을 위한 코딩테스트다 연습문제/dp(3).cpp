#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	int arr[1001], dp[1001] = {0};

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[arr[i]] = 1;
	}

	for (int i = 2; i <= m; i++)
	{
		if (dp[i] == 0)
			dp[i] = 10000000;
		for (int j = 1; j <= i / 2; j++)
		{
			if (dp[j] == 0 || dp[i - j] == 0)
				continue;
			dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
	}
	if (dp[m] == 10000000)
		cout<<-1;
	else
		cout<<dp[m];
}
