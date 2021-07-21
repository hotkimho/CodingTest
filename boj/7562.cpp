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
int start_x, start_y;
int goal_x, goal_y;
int cnt;

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
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
		if(i == (goal_y + 2) && j == (goal_x + 2))
		{
			return;
		}
		is_visited[i][j] = 1;
		for(int k=0; k<8; k++)
		{
			int x = j + dx[k];
			int y = i + dy[k];
			if(is_visited[y][x] == 0 && map[y][x] == 1)
			{
				c.push(cnt + 1);
				q.push(make_pair(y,x));
				is_visited[y][x] = 1;
			}
		}
	}
}



int main() {
	
	int l, T;

	cin>>T;
	for(int k=0; k<T; k++)
	{
		scanf("%d", &l);
		for(int i=2; i<l+2; i++)
		{
			for(int j=2; j<l+2; j++)
			{
				map[i][j] = 1;
			}
		}
		scanf("%d %d", &start_x, &start_y);
		scanf("%d %d", &goal_x, &goal_y);
		q.push(make_pair(start_y + 2, start_x + 2));
		c.push(0);
		bfs();
		cout<<cnt<<endl;
		
		while(!q.empty())
			q.pop();

		while(!c.empty())
			c.pop();
		for(int i=2; i<l+2; i++)
			for(int j=2; j<l+2; j++)
			{
				map[i][j] = 0;
				is_visited[i][j] = 0;
			}
		cnt = 0;
	}
}
