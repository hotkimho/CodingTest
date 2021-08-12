#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;

// 1 -> 1 -> 1
// 2 -> 00 11 -> 2
// 3 -> 001 100 111 -> 3
// 4 -> 1001 0011 1111 1100 0000 -> 5
// ?? fibo???
//

int arr[1000001];

int main()
{
	int n;
	int result = 0;

	scanf("%d", &n);
	arr[1] = 1;
	arr[2] = 2;

	for(int i=3; i<=n; i++)
	{
		arr[i] = (arr[i-1] + arr[i-2]) % 15746;
	}
	
	cout<<arr[n];
	return 0;
}
