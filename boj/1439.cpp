#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

int arr[100000];
int n, result;

int main(){
    //1. 문제 입력
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	int flag = 0;
	string str;
	cin >> str;
	
	for (int i = 1; i < str.size(); i++)
	{	
		char tmp;
		if (str[i] != str[i - 1])
		{
			tmp = str[i];
			while (str[i] == tmp && i < str.size())
				i++;
			result++;
		}
	}
	cout << result;
}