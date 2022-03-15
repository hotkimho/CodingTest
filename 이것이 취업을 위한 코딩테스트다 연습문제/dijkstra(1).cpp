#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 1000000000

vector<pair<int, int> > g[10001];
int visited[10001];
int dis[10001];
int n, m;


int get_smallest_node()
{
	int minValue = INF;
	int minIndex;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;
		if (minValue > dis[i])
		{
			minValue = dis[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void dijkstra(int start)
{
	dis[start] = 0;
	visited[start] = 1;
	for (int i = 0; i < g[start].size(); i++)
		dis[g[start][i].first] = g[start][i].second;
	
	for (int i = 0; i < n - 1; i++)
	{
		int minNode = get_smallest_node();
		visited[minNode] = 1;
		for (int i = 0; i < g[minNode].size(); i++)
		{
			int des = g[minNode][i].first;
			int dist = g[minNode][i].second;
			if (dis[minNode] + dist < dis[des])
				dis[des] = dis[minNode] + dist;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int start;
	int v1, v2, distance;

	cin >> n >> m >> start;

	for (int i = 0; i < 11; i++)
	{
		cin >> v1 >> v2 >> distance;
		g[v1].push_back(make_pair(v2, distance));
	}
	for (int i = 1; i <= n; i++)
		dis[i] = INF;
	dijkstra(start);
	for (int i = 1; i <= n; i++)
		cout<<dis[i]<<endl;
}