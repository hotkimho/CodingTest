#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;


int is_visited[1005][1005];
int map[1005][1005];
int N,M;
queue<int> result;

void bfs(int i, int j)
{
        queue<pair<int,int>> q;
	//queue<int> result;
	pair<int, int> p;

        q.push(make_pair(i, j));
	result.push(1);
	//is_visited[i][j] = 1;

        while(!q.empty())
        {
                p = make_pair(q.front().first, q.front().second);
		int qr = result.front();
		result.pop();
                q.pop();
		int a = p.first;
		int b = p.second;
		is_visited[a][b] = 1;
		if (a==N && b == M)
		{
			cout<<qr;
			return;
		}

		if(is_visited[a-1][b] == 0 && map[a-1][b])
		{
			q.push(make_pair(a-1,b));
			is_visited[a-1][b] = 1;
			result.push(qr+1);
		}

		if(is_visited[a][b-1] == 0 && map[a][b-1])
		{
			q.push(make_pair(a,b-1));
			is_visited[a][b-1] = 1;
			result.push(qr+1);
		}
		if(is_visited[a+1][b] == 0 && map[a+1][b])
		{
			result.push(qr+1);
			q.push(make_pair(a+1,b));
			is_visited[a+1][b] = 1;
		}

		if(is_visited[a][b+1] == 0 && map[a][b+1])
		{
			result.push(qr + 1);
			q.push(make_pair(a,b+1));
			is_visited[a][b+1] = 1;
		}
        }
}



int main() {
	char str[103];
	
	cin >> N >> M;
	
	for(int i=1; i<=N; i++){
		cin >> str;
		for(int j=1; j<=M; j++)
			map[i][j] = str[j-1] - '0'; 
	}
	bfs(1,1);
}
