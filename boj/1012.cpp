#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


int is_visited[53][53];
int map[53][53];
vector<int> result;
int tmp;


void dfs(int i, int j)
{
	if (is_visited[i][j] == 1)
		return ;
	
	is_visited[i][j] = 1;
	tmp++;
	for(int k=0; k<4; k++)
	{
		if(map[i][j-1] == 1)	
			dfs(i, j-1);
		if(map[i-1][j] == 1)
			dfs(i-1, j);
		if(map[i+1][j] == 1)
			dfs(i+1, j);
		if(map[i][j+1] == 1)
			dfs(i, j+1);
	}
}


int main() {
	int T;
	int M,N,K;
	int num1, num2;
	cin >> T;
	int count;
	for (int t=0; t<T; t++)
	{	
		count = 0;
		scanf("%d %d %d", &M, &N, &K);
		for(int i=0; i<K; i++)
		{
			scanf("%d %d", &num1, &num2);
			map[num2+1][num1+1] = 1;
		}
		
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=M; j++)
			{
				if(is_visited[i][j] == 0 && map[i][j])
				{
					dfs(i, j);
					if(tmp != 0)
					{
						count++;
						tmp = 0;
					}
				}
			}
		}
		for(int i=1; i<=N; i++)
			for(int j=1; j<=M; j++)
			{
				is_visited[i][j] = 0;
				map[i][j] = 0;
			}
		cout<<count<<endl;
	}
}
