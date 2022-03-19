#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int S[21][21];
int result = 1000000000;
int visited[21];
vector<int> start;
vector<int> link;

void start_link(int idx, int count)
{
	if (count == n / 2)
	{
		//for (int k = 1; k <= n; k++)
		//{
		//	if (numCount[k])
				
		//}
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue
		else
		{
			visited[i] = 1;
			start_link(i, count + 1);
			visited[i] = 0;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> S[i][j];
	}
	start_link(0, 0, 1);
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