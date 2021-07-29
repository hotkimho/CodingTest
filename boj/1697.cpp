#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> g[100005];
queue<int> q;
queue<int> q_c;
int visited[100005];
int n,k;
int result;


void bfs()
{
	if (n == k)
	{
		result = 0;
		return;
	}
	while(!q.empty())
	{
		int cur_n = q.front();
		int cur_c = q_c.front();

		q.pop();
		q_c.pop();
		if (visited[cur_n])
			continue;
		visited[cur_n] = 1;

		if (cur_n == k)
		{
			result = cur_c;
			return;
		}
		if (cur_n - 1 >= 0 && visited[cur_n-1] == 0)	
		{
			q.push(cur_n - 1);
			q_c.push(cur_c + 1);
			//visited[cur_n] = 1;
		}
		if (cur_n + 1 < 100001 && visited[cur_n+1] == 0)
		{
			q.push(cur_n + 1);
			q_c.push(cur_c + 1);
			//visited[cur_n] = 1;
		}
		if (cur_n * 2 <= 100000 && visited[cur_n*2] == 0)
		{
			q.push(cur_n * 2);
			q_c.push(cur_c + 1);
			
		}
	}
}
int main() {
	cin >>n >> k;
	q.push(n);
	q_c.push(0);
	
	bfs();
	cout<<result;

}
