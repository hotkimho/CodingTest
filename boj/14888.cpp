#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 1000000000

int numberArray[12];
int opArray[5];
int n;
int maxValue = -10000000, minValue = 1200000000;
void recursiveOp(int index, int result)
{
	if (index > n)
	{
		maxValue = max(maxValue, result);
		minValue = min(minValue, result);
		return ;
	}
	for (int i = 1; i <= 4; i++)
	{
		if (opArray[i] > 0)
		{
			opArray[i]--;
			if (i == 1) //더하기
				recursiveOp(index + 1, result + numberArray[index]);
			else if (i == 2) //빼기
				recursiveOp(index + 1, result - numberArray[index]);
			else if (i == 3)
				recursiveOp(index + 1, result * numberArray[index]);
			else if (i == 4)
				recursiveOp(index + 1, result / numberArray[index]);
			opArray[i]++;
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &numberArray[i]);
	for (int i = 1; i <= 4; i++)
		scanf("%d", &opArray[i]);
	recursiveOp(2, numberArray[1]);
	cout << maxValue << endl << minValue;
}