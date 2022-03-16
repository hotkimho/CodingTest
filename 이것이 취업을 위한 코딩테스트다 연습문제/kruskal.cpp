#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 1000000000

vector<pair<int, pair<int, int> > >g;
int parent[10000];
int v, e;
int result = 0;

int getParent(int x)
{
	if (parent[x] != x)
		parent[x] = getParent(parent[x]);
	return parent[x];
}

void unionParent(int a, int b)
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
	int edge = 0;
	for (int i = 0; i < g.size(); i++)
	{	
		int cost = g[i].first;
		int v1 = g[i].second.first;
		int v2 = g[i].second.second;

		cout << v1 << " - " << v2 << " = " << cost << endl;
		if (getParent(v1) == getParent(v2))
			continue;
		unionParent(v1, v2);
		result += cost;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> v >> e;

	for (int i = 1; i <= v; i++)
		parent[i] = i;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g.push_back({c, {a, b}});
	}
	sort(g.begin(), g.end());
	kruskal();
	cout<<result;
}