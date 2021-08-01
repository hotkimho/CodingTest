#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;

int arr[10006];

int main()
{
	int n,idx;
	int p_arr[10006];
	int T,cur_v;
	int result[2];
	for(int i=2; i<=sqrt(10005); i++)
	{
		for(int j=i*2; j<=10005; j+=i)
			arr[j] = 1;
	}
	
	idx = 0;
	for(int i=2; i<=10005; i++)
		if(arr[i] == 0)
			p_arr[idx++] = i;
	
	cin >> T;
	result[0] = 0;
	result[1] = 1000000;
	for(int k=0; k<T; k++)
	{
		result[0] = 0;
		result[1] = 1000000;
		scanf("%d", &n);
		for(int i=0; i<idx; i++)
		{
			cur_v = p_arr[i];
			for(int j=i; j<idx; j++)
			{
				if((cur_v + p_arr[j]) == n)
				{
					if(abs(result[0]-result[1]) > abs(cur_v - p_arr[j]))
					{
						result[0] = cur_v;
						result[1] = p_arr[j];
					}
					break;
				}
			}
		}
		printf("%d %d\n", result[0], result[1]);
	}
}
