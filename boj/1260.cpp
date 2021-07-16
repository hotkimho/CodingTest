#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int is_visited[1002];
vector<int> g[1002];

void dfs(int start)
{
	if (is_visited[start])
		return ;

	
	is_visited[start] = 1;
	cout<<start<<" ";

	for(int i=0; i<g[start].size(); i++)
	{
		dfs(g[start][i]);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	is_visited[start] = 1;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		cout<<v<<" ";
		for(int i=0; i< g[v].size(); i++)
		{
			int tmp = g[v][i];
			if (!is_visited[tmp]) 
			{
				q.push(tmp);
				is_visited[tmp] = 1;
			}
		}
	}
}
int main() {
	int N,M,start_V;
	int v1, v2;
	cin >> N >> M >> start_V;

	for(int i=0; i<M; i++)
	{
		scanf("%d %d", &v1, &v2);
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	for(int i=1; i<=N; i++)
		sort(g[i].begin(), g[i].end());
	dfs(start_V);
	cout<<endl; 
	for(int i = 0; i<N + 1; i++)
		is_visited[i] = 0;
	bfs(start_V);
}
