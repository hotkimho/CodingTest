#include <cctype>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;


int ho_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

int ho_isDigit(char c)
{
	if ('0' <= c && c <= '9')
		return 1;
	return 0;
}
int main()
{
	int len;
	char input[51];
	int result = 0;
	int tmp = 0;
	int opFlag = 0;

	cin>>input;
	len = ho_strlen(input);

	for (int i=0; i<len; i++)
	{
		if (ho_isDigit(input[i]))
		{
			tmp *= 10;
			tmp = tmp + (input[i] - '0');
		}
		else
		{
			if (opFlag)result = result - tmp;
			else
				result = result + tmp;
			tmp = 0;
			if (input[i] == '-')
				opFlag = true;
		}
		cout<<opFlag<<endl;
	}
	if (opFlag)
		result = result -tmp;
	else
		result = result + tmp;
	cout<<result;
}

