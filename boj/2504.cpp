#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	string bracket;
	stack<char> stk;
	long long result = 0;
	long long tmp = 1;

	cin >> bracket;

	for (int i = 0; i < bracket.size(); i++)
	{
		if (bracket[i] == '(')
		{
			tmp *= 2;
			stk.push(bracket[i]);
		}
		else if (bracket[i] == '[')
		{
			tmp *= 3;
			stk.push(bracket[i]);
		}

		if (bracket[i] == ')' && (stk.empty() || stk.top() == '['))
		{
			result = 0;
			break;
		}
		if (bracket[i] == ']' && (stk.empty() || stk.top() == '('))
		{
			result = 0;
			break;
		}
		if (bracket[i] == ')')
		{
			stk.pop();
			if (bracket[i - 1] == '(')
				result += tmp;
			else if (bracket[i - 1] == '[')
			{
				result = 0;
				break;
			}
			tmp /= 2;
		}
		else if (bracket[i] == ']')
		{
			stk.pop();
			if (bracket[i - 1] == '[')
				result += tmp;
			else if (bracket[i - 1] == '(')
			{
				result = 0;
				break;
			}
			tmp /= 3;
		}
	}
	if (!stk.empty())
		result = 0;
	cout << result;
}