#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int dp[41][41]={0,};
int fibo[41];
/*
 0 1 0
 1 0 1
 2 1 1
 3 1 2
 4 2 3
 */
void fibonacci()
{
	for(int i=3; i<41; i++)
	{
		dp[i][0] = dp[i-1][0] + dp[i-2][0];
		dp[i][1] = dp[i-1][1] + dp[i-2][1];
	}
}
int main()
{
	int T;
	int N;

	dp[0][0] = 1;
	dp[1][1] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	fibonacci();

	scanf("%d", &T);
	for(int i=0; i<T; i++)
	{
		scanf("%d", &N);
		printf("%d %d\n", dp[N][0], dp[N][1]);
	}
}

