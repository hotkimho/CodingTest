#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 1000000000

vector<pair<int, int> >g[30001];
priority_queue<pair<int, int> > pq;
int dis[10001];
int n, m, c;
int longTime = -1;
int cityOfCount = 0;

void dijkstra(int start)
{
	dis[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int nodeDistance = -pq.top().first;
		int nodeNumber = pq.top().second;
		pq.pop();
		for (int i = 0; i < g[nodeNumber].size(); i++)
		{
			int distance = nodeDistance + g[nodeNumber][i].second;
			int node = g[nodeNumber][i].first;
			if (dis[node] > distance)
			{
				longTime = max(longTime, distance);
				pq.push(make_pair(-distance, node));
				cityOfCount++;
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> c;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= n; i++)
		dis[i] = INF;

	dijkstra(c);
	cout << cityOfCount << " " << longTime;
}