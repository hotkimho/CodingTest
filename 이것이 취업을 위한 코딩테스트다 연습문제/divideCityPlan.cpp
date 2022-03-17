#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 1000000000

vector<pair<int, pair<int, int> > > g;
int parent[100001];
int n, m, result;

int getParent(int x)
{
	if (parent[x] != x)
		parent[x] = getParent(parent[x]);
	return parent[x];
}

void unionTeam(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

void kruskal()
{
	int lastCost = 0;
	for (int i = 0; i < g.size(); i++)
	{
		int cost = g[i].first;
		int a = g[i].second.first;
		int b = g[i].second.second;
		if (getParent(a) == getParent(b))
			continue;
		unionTeam(a, b);
		result += cost;
		lastCost = cost;
	}
	result -= lastCost;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		g.push_back({cost, {a, b}});
	}
	sort(g.begin(), g.end());
	kruskal();
	cout<<result;
}