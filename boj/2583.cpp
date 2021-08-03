#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;

int map[102][102];
int result[102];
int c;
int y,x;
int t_x[4] ={-1,1,0,0};
int t_y[4] ={0,0,1,-1};


void dfs(int i, int j)
{
	if(map[i][j])
		return;
	map[i][j] = 1;
	c++;
	for(int t=0; t<4; t++)
	{
		int tmp_x = t_x[t] + j;
		int tmp_y = t_y[t] + i;
		if ( tmp_x >= 0 && tmp_x < x && tmp_y >= 0 && tmp_y < y && map[tmp_y][tmp_x] == 0)
			dfs(tmp_y, tmp_x);
	}
}
int main()
{
	int k;
	int s_x,s_y,e_x,e_y;
	cin >> y >> x >> k;
	
	for(int t=0; t<k; t++)
	{
		scanf("%d %d %d %d", &s_x, &s_y, &e_x, &e_y);
		for(int i=s_y; i<e_y; i++)
		{
			for(int j=s_x; j<e_x; j++)
				map[i][j] = 1;
		}
	}
	int a_count = 0;
	for(int i=y-1; i>=0; i--)
	{
		for(int j=0; j<x; j++)
		{
			if(map[i][j] == 0)
			{
				c = 0;
				dfs(i,j);
				result[a_count++] = c;
			}
		}
	}
	cout<<a_count<<endl;
	sort(result, result + a_count);
	for(int i=0; i<a_count; i++)
		cout<<result[i]<<" ";
	
}
