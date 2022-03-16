#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 1000000000

vector<int> g[10000];
queue<int> q;
int inDegree[10000];
int v, e;


void topologySort()
{
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (int i = 0; i < g[node].size(); i++)
		{
			int decreaseNode = g[node][i];
			inDegree[decreaseNode]--;
			if (inDegree[decreaseNode] <= 0)
				q.push(decreaseNode);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		inDegree[b]++;
		g[a].push_back(b);
	}
	
	for (int i = 1; i <= v; i++)
		if (inDegree[i] == 0)
			q.push(i);
	topologySort();
}