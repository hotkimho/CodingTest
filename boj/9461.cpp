#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;


long long arr[101];

// 1 -> 1
// 2 -> 1
// 3 -> 1
// 4 -> 2
// 5 -> 2
// 6 -> 3
// 7 -> 4
// 8 -> 5
// 9 -> 7
// 10 ->9
int main()
{
	int t,n;

        scanf("%d", &t);
	
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	
	for(int i=6; i<=100; i++)
		arr[i] = arr[i-1] + arr[i-5];
	for(int k=1; k<=t; k++)
	{
		scanf("%d", &n);
		//for(int i=6; i<=n; i++)
		//{
		//	arr[i] = arr[i-1] + arr[i-5];
		//}

		cout<<arr[n]<<endl;
	}
        return 0;
}
