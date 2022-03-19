#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int n, m;
int A[500001];
int B[500001];

int binary_search_card(int findNum, int start, int end)
{
	int mid = (start + end) / 2;

	if (start > end)
		return 0;
	else if (A[mid] == findNum)
		return 1;
	else if (A[mid] > findNum)
		return binary_search_card(findNum, start, mid - 1);
	else if (A[mid] < findNum)
		return binary_search_card(findNum, mid + 1, end);
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A, A + n);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &B[i]);
		printf("%d ",binary_search_card(B[i], 0, n));
	}
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