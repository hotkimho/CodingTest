#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int coin[10];
	int cost, coinNum;
	int count = 0;

	cin >> coinNum >> cost;

	for(int i=0; i<coinNum; i++)
		scanf("%d", &coin[i]);

	for(int i=coinNum-1; i>=0; i--)
	{
		if (cost / coin[i])
		{
			count = count + (cost / coin[i]);
			cost = cost % coin[i];
		}
	}
	cout << count;
}

