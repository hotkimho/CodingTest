#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool second_sort(pair <int, int> p, pair <int, int> p2)
{
	if(p.second == p2.second)
		return  p.first < p2.first;
	else
		return p.second < p2.second;
}
int main()
{
	int N;
	vector <pair<int, int>> v;
	int result = 0;
	int endTime = -1;

	cin>>N;
	int a, b;
	for(int i=0; i<N; i++)
	{
		scanf("%d %d", &a, &b);
		v.push_back(pair<int, int>(a,b));
	}
	
	sort(v.begin(), v.end(),second_sort);
	endTime = v[0].second;
	for(int i=1; i<N; i++)
	{
		if (v[i].first >= endTime)
		{
			result++;
			endTime = v[i].second;
		}
	}
	cout<<result+1;

	
}
