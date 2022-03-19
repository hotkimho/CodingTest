#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int q[10001];
int frontIdx = 0;
int backIdx = -1;
int qSize = 0;

bool qempty()
{
	if (qSize == 0)
		return true;
	return false;
}

void push(int number)
{
	q[++backIdx] = number;
	qSize++;
}

void pop()
{
	if (qempty())
		printf("-1\n");
	else
	{
		printf("%d\n", q[frontIdx++]);
		qSize--;
	}
}

void size()
{
	printf("%d\n", qSize);
}


void front()
{
	if (qempty())
		printf("-1\n");
	else
		printf("%d\n", q[frontIdx]);
}

void back()
{
	if (qempty())
		printf("-1\n");
	else
		printf("%d\n", q[backIdx]);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, number;
	char input[10];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (!strcmp(input, "push"))
		{
			cin >> number;
			push(number);
		}
		else if (!strcmp(input, "pop"))
			pop();
		else if (!strcmp(input, "size"))
			size();
		else if (!strcmp(input, "empty"))
			cout<<qempty()<<endl;
		else if (!strcmp(input, "front"))
			front();
		else if (!strcmp(input, "back"))
			back();
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