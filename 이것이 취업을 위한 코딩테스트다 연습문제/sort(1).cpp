#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;


bool compare(int a, int b)
{
	return a > b;
}

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main() 
{
	int A[100000], B[100000];
	int n, k;

	cin >> n >> k;

	for(int i = 0; i < n; i++)
		cin >> A[i];
	for(int i = 0; i < n; i++)
		cin >> B[i];

	sort(A, A + n);
	sort(B, B + n, compare);

	for (int i = 0; i < k; i++)
	{
		swap(&A[i], &B[k - 1 - i]);
	}
	int result = 0;
	for (int i = 0; i < n; i++)
		result += A[i];
	cout<< result;

}
