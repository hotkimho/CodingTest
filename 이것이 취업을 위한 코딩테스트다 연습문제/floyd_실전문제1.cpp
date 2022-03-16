#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 1000000000

int g[101][101];
int dis[10001];
int n, m, x, k;

void floyd_warshall()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j<= n; j++)
			if (i == j)
				g[i][j] = 0;
			else
				g[i][j] = INF;
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}
	cin >> x >> k;
	floyd_warshall();
	int result = g[1][k] + g[k][x];
	if (result >= INF)
		cout << -1;
	else
		cout << result;
}