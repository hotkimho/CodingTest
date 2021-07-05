#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>

using namespace std;


int main()
{
	int num;
	int input;
	stack<int> stk;

	cin>>num;
	for (int i=0; i<num; i++)
	{
		scanf("%d", &input);
		if (input == 0)
			stk.pop();
		else
			stk.push(input);
	}

	int sum = 0;
	while(!stk.empty())
	{
		sum += stk.top();
		stk.pop();
	}

	cout<<sum;
}
