#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

vector<int> graph[1000];
queue<int> q;
bool visited[1000];

void dfs(int v)
{
   visited[v] = 1;
   cout << v << " ";

   for (int i = 0; i < graph[v].size(); i++)
      if (visited[graph[v][i]] == 0)
         dfs(graph[v][i]);
}

void bfs(int v)
{
   visited[v] = 1;
   q.push(v);

   while (!q.empty())
   {
      int x = q.front();
      q.pop();
      cout << x << " ";
      for (int i = 0; i < graph[x].size(); i++)
      {
         int value = graph[x][i];
         if (visited[value] == 0)
         {
            q.push(value);
            visited[value] = 1;
         }
      }
   }
}
int main() 
{  
   int v1, v2;
   int n;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cin >> v1 >> v2;
      graph[v1].push_back(v2);
      graph[v2].push_back(v1);
   }

   dfs(1);
   cout<<endl;
   bfs(1);
}