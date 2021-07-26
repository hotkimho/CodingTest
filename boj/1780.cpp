#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int arr[2200][2200];
int c[3];

void recur(int y, int x,int size)
{
	int n;
	int tmp[3] ={0,0,0};
	for(int i=y; i<size + y; i++)
	{
		for(int j=x; j<size + x; j++)
		{
			if(arr[i][j] == -1)
				tmp[0]++;
			else if(arr[i][j] == 0)
				tmp[1]++;
			else if(arr[i][j] == 1)
				tmp[2]++;
		}
	}
	n = size * size; 
	if(tmp[0] == n)
		c[0]++;
	else if(tmp[1] == n)
		c[1]++;
	else if(tmp[2] == n)
		c[2]++;
	else
	{
		int t_size = size/3;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				recur(y + i*t_size, x + j*t_size, t_size);
			}
		}
	}

}
int main() {
	int N;
	cin >>N;

	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin>>arr[i][j];
	recur(1,1,N);
	for(int i=0; i<3; i++)
		cout<<c[i]<<endl;
}
