#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int arr[10001];
	int N;
	int tmp;
	int max = 0;

	scanf("%d", &N);
	
	for (int i=0; i<10001; i++)
		arr[i] = 0;

	for (int i=0; i<N; i++)
	{
		scanf("%d", &tmp);
		arr[tmp]++;
		if (max < tmp)
			max = tmp;
	}

	for (int i=0; i<=max; i++)
		if (arr[i])
			for(int j=0; j<arr[i]; j++)
				printf("%d\n", i);
}
