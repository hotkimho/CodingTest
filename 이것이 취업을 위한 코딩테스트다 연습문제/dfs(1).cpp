#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

int graph[1001][1001];
int dy[4] = {0, 0, -1, +1};
int dx[4] = {-1, +1, 0, 0};
int N, M;
int dfs(int x, int y)
{
   if (x < 1 || y < 1 || x > M || y > N)
      return 0;
   
   if (graph[y][x] == 0)
   {
      graph[y][x] = 1;
      for (int i = 0; i < 4; i++)
         dfs(y + dy[i], x + dx[i]);
      return 1;
   } 
   return 0;
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

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			count += dfs(i, j);
   cout<<count;
}