#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int arr[101]={0,};
	int primeNumber[1001]={0,};
	int N;
	int num;
	int count = 0;

	primeNumber[1] = 1;
	for (int i=2; i<sqrt(1001); i++)
	{
		for(int j=i*i; j<1001; j+=i)
		{
			primeNumber[j] = 1;
		}
	}
	scanf("%d", &N);

	for(int i=0; i<N; i++)
	{
		scanf("%d", &num);
		if (primeNumber[num] == 0)
			count++;		
	}
	printf("%d", count);
}

