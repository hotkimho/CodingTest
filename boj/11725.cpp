#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector <int>graph[100005];
int is_visited[100005];
int result[100005];
queue <int> q;

void bfs()
{
	int V;
	while(!q.empty())
	{
		int V = q.front();
		q.pop();
		
		is_visited[V] = 1;

		for(int i=0; i<graph[V].size(); i++)
		{
			if(is_visited[graph[V][i]] == 0)
			{
				q.push(graph[V][i]);
				is_visited[graph[V][i]] = 1;
				result[graph[V][i]] = V;
			}
		}
	}
}



int main() {

	int N;
	int n1, n2;

	cin>>N;
	for(int i=1; i<N; i++)
	{
		scanf("%d %d", &n1, &n2);
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	q.push(1);
	bfs();
	for(int i=2; i<=N; i++)
		printf("%d\n", result[i]);

}
