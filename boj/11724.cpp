#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector <int> g[1003];
int visited[1003];
int c;


void dfs(int start)
{
	if(visited[start])
		return ;

	visited[start] = 1;
	c++;

	for(int i=0; i<g[start].size(); i++)
	{
		dfs(g[start][i]);
	}

}
int main() {
	int n, m;
	int u, v;
	int result = 0;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i=1; i<=n; i++)
	{
		if(g[i].size() == 0)
			result++;
		for(int j=0; j<g[i].size(); j++)
		{
			if(visited[i] == 0)
				dfs(g[i][j]);
			if(c != 0)
			{
				result++;
				c = 0;
			}
		}	
	}
	cout<<result;
}
