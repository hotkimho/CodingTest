#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 1000000000

vector<pair<int, int> > g[10001];
priority_queue<pair<int, int> > pq;
int visited[10001];
int dis[10001];
int n, m;

void dijkstra(int start)
{
	pq.push(make_pair(0, start));
	dis[start] = 0;
	visited[start] = 1;
	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		
		if (dis[node] < dist)
			continue;
		for (int i = 0; i < g[node].size(); i++)
		{
			int d = dist + g[node][i].first;
			int des = g[node][i].second;
		
			if (d < dis[des])
			{
				dis[des] = d;
				pq.push(make_pair(-d, des));
			}
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
		g[v1].push_back(make_pair(distance, v2));
	}
	for (int i = 1; i <= n; i++)
		dis[i] = INF;
	dijkstra(start);
	for (int i = 1; i <= n; i++)
		cout<<dis[i]<<endl;
}