#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
int t[17];
int p[17];
int dp[17];
int n;
  
bool check_consulting(int day)
{
	if (t[day] + day >= n + 1)
		return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	int maxValue = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		t[i] = a;
		p[i] = b;
	}

	for (int i = n; i > 0; i--)
	{
		if (i + t[i] > n + 1)
			dp[i] = dp[i + 1];
		else
		{
			//printf("[%d] = (%d + %d(%d) or %d\n", i, p[i], dp[i + t[i]],i + t[i], dp[i+1]);
			dp[i] = max(p[i] + dp[i + t[i]], dp[i + 1]);
		}
	}
	cout<<dp[1];
}

/*30 -> 4, 6
00000000
00000000
00000000
00000100
8 * 2 + 4
00000
00000
00000
00000
00000

0000
0000
0000
0000
0000
*/
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	freopen("input.txt", "r", stdin);
//	int arr[301][301];
//	int tmpArr[301][301];
//	bool flag = false;
//	int n, m, r;
//	cin >> n >> m >> r;

//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			cin >> arr[i][j];
	
//	//1. 열의 값이 1보다 작아지면 행을 증가시킨다.
//	//2. 열의 값이 M보다 커지면 행을 감소시킨다.

//	for (int t = 1; t <= n / 2; t++)
//	{
//		int x = 1, y = 1;
//		for (int i = 1; i <= n * m; i++)
//		{
//			x += i / n
//		}
//	}

//}