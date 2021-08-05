#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;

vector <int>g[101];
int visited[101];
queue <int>q;
queue <int>q_c;
int c;
int x,y;

void bfs()
{
	while(!q.empty())
	{
		int v = q.front();
		int tmp_c = q_c.front();
		
		q.pop();
		q_c.pop();
		
		visited[v] = 1;
		if( v == y)
		{
			c = tmp_c;
			return;
		}

		for(int i=0; i<g[v].size(); i++)
		{
			if(visited[g[v][i]] == 0)
			{
				q.push(g[v][i]);
				q_c.push(tmp_c + 1);
			}
		}
	}
}
int main()
{
	int n,m;

	cin >> n;
	cin >> x >> y;
	cin >> m;
	
	int n1,n2;

	for(int i=0; i<m; i++)
	{
		scanf("%d %d", &n1,&n2);
		g[n1].push_back(n2);
		g[n2].push_back(n1);
	}
	q.push(x);
	q_c.push(0);
	bfs();
	if(c != 0)
		cout<<c;
	else
		cout<<-1;

}
