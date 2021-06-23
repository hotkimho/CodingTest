#include <iostream>
#include <algorithm>
using namespace std;


int get_max_value(int B[][2], int n)
{
	int max = -1;
	int count;
	for(int i=0; i<n; i++)
	{
		if (max < B[i][0] && B[i][1] == 0)
		{
			max = B[i][0];
			count = i;
		}
	}
	B[count][1] = 1;
	return max;
}


int main()
{
	int n;
	int A[51],B[51][2];
	int S = 0;

	cin >> n;
	for(int i=0; i<n; i++)
		cin>>A[i];
	for(int i=0; i<n; i++)
	{
		cin>>B[i][0];
		B[i][1] = 0;
	}
	sort(A, A + n);
	for(int i=0; i<n; i++)
		S += A[i] * get_max_value(B, n);
	cout<<S<<endl;
}
