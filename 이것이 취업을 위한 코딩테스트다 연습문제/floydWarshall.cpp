#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 100000000
int g[1001][1000];
int n, m;

void floyd_warshall()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				cout << j << " -> " << i << " -> " << k;
				g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
				cout<<" = " << g[j][k]<<endl;
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				g[i][j] = 0;
			else
				g[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		g[a][b] = c;
	}
	floyd_warshall();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << g[i][j]<<" ";
		cout<<endl;
	}

}