#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

int graph[1001][1001];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int N, M;

int bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 1 || ny < 1 || nx > M || ny > N)
				continue;
			if (graph[ny][nx] == 0)
				continue;
			if (graph[ny][nx] == 1)
			{
				printf("%d %d %d\n", ny, nx, graph[y][x] + 1);
				graph[ny][nx] = graph[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
	return graph[N][M];
}

int main() 
{  
   string input;
   int count = 0;

   cin >> N >> M;
   for (int i = 1; i <= N; i++)
   {
	   cin >> input;
	   for (int j = 1; j <= M; j++)
	   graph[i][j] = input[j-1] - '0';
   }
	cout<<bfs()<<endl;
	for (int i = 1; i<= N; i++)
	{
		for (int j = 1; j<= M; j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;
	}
}
