#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 1000000000

int indegree[501];
int subjectTime[501];
vector<int> g[501];
queue<int> q;
int n;

void curriculum()
{
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		cout << "선택한 노드 : " << node <<" 번 노드"<<endl;
		for (int i = 0; i < g[node].size(); i++)
		{
			int nearNode = g[node][i];
			cout << "인접한 노드 : " << nearNode << " 번 노드"<<endl;
			indegree[nearNode]--;
			if (indegree[nearNode] <= 0)
			{
				q.push(nearNode);
				subjectTime[nearNode] += subjectTime[node];
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		subjectTime[i] = input;
		while (1)
		{
			cin >> input;
			if (input == -1)
				break;
			g[input].push_back(i);
			indegree[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);
	curriculum();
	for (int i = 1; i <= n; i++)
		cout<<subjectTime[i]<<endl;
}