#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int arr[130][130];
int N;
int white, blue;

void recur(int x, int y, int size)
{
	int n, c = 0;
	n = size * size;
	for(int i = y; i<size + y; i++)
		for(int j=x; j<size + x; j++)
			if(arr[i][j] == 1 )
				c++;

	if (c == n)
		blue++;
	else if(c == 0)
		white++;
	else
	{
		int divSize = size/2;
		recur(x, y, divSize);
		recur(x + divSize, y, divSize);
		recur(x, y + divSize, divSize);
		recur(x + divSize, y + divSize, divSize);
	}
}
int main() {

	cin >> N;
	int num;

	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			scanf("%d", &arr[i][j]);
	recur(1,1, N);

	cout<<white<<endl<<blue;
}
