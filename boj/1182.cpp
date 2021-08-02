#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;

int arr[22];
int S,N,c;

void recur(int idx, int n)
{
	if (idx == N)
		return;

	n += arr[idx];
	if (n == S)
		c++;

	//for(int i=idx; i<N; i++)
	//{
		recur(idx+1, n - arr[idx]);
		recur(idx+1, n);
	//}
}

int main()
{
	int num;

	cin >> N >> S;

	for(int i=0; i<N; i++)
		cin >> arr[i];
	
	recur(0, 0);
	cout<<c<<endl;
}
