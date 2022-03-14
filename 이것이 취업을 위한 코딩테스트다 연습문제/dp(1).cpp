#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	int arr[30002] = {0,};
	int x, result = 0;
	freopen("input.txt", "r", stdin);
	cin >> x;

	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 1;

	int count = 0;
	for (int i = 6; i <= x; i++)
	{
		//이 값은 무조건 있을 수 밖에 없음
		int minValue = arr[i - 1];
		
		if (i % 5 == 0)
			minValue = min(minValue, arr[i / 5]);
		if (i % 3 == 0)
			minValue = min(minValue, arr[i / 3]);
		if (i % 2 == 0)
			minValue = min(minValue, arr[i / 2]);
		arr[i] = minValue + 1;
	}
	cout << arr[x]<<endl;
	
}
