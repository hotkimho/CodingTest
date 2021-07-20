#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;


int is_visited[1005][1005];
int map[1005][1005];
queue <pair<int, int>> q;
queue <int>c;
int N,M;
int result;
int cnt;

void bfs()
{
	int i;
	int j;
	while(!q.empty())
	{
		i = q.front().first;
		j = q.front().second;
		cnt = c.front();
		c.pop();
		q.pop();
		is_visited[i][j] = 1;
		map[i][j] = 3;
		if(is_visited[i-1][j] == 0 && map[i-1][j] == 2)
		{
			q.push(make_pair(i-1, j));
			c.push(cnt + 1);
			is_visited[i-1][j] = 1;
		}
	
		if(is_visited[i][j-1] == 0 && map[i][j-1] == 2)
		{
			q.push(make_pair(i, j-1));
			c.push(cnt + 1);
			is_visited[i][j-1] = 1;
		}
		if(is_visited[i+1][j] == 0 && map[i+1][j] == 2)
		{
			q.push(make_pair(i+1, j ));
			c.push(cnt+1);
			is_visited[i+1][j] =1;
		}	

		if(is_visited[i][j+1] == 0 && map[i][j+1] == 2)
		{
			q.push(make_pair(i, j+1));
			c.push(cnt+1);
			is_visited[i][j+1] =1;
		}
		
	}
}



int main() {
	int n,today = 0;
	cin >> N >> M;
	result = N * M;
	for(int i=1; i<=M; i++)
	{
		for(int j=1; j<=N; j++)
		{
			scanf("%d", &n);
			if (n == 1)
			{
				q.push(make_pair(i,j));
				c.push(0);
			}
			if (n == 0)
				map[i][j] = 2;
			else
				map[i][j] = n;
		}
	}
	bfs();

	for(int i=1; i<=M; i++)
	{
		for(int j=1; j<=N; j++)
			if(map[i][j] == 2)
				cnt = -1;
	}
	cout<<cnt;
}
