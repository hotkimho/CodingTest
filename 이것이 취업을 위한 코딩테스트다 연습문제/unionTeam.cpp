#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 1000000000

int team[100001];
int n, m;

int getParent(int x)
{
	if (team[x] != x)
		team[x] = getParent(team[x]);
	return team[x];
}

void unionTeam(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b)
		team[b] = a;
	else
		team[a] = b;
}

bool checkTeam(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b)
		return true;
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		team[i] = i;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		if (a == 0)
			unionTeam(b, c);
		else
			if (checkTeam(b, c))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
	}
}