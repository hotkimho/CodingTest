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
	int arr[101];
	int dp[101] = {0,};
	int n;
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[1] = arr[1];
	dp[2] = max(arr[1],arr[2]);

	for (int i = 3; i<= n; i++)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
	}
	cout << dp[n];
}