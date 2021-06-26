#include <iostream>
#include <stdio.h>
using namespace std;


void char_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int strlen(char *str)
{
	int i = 0;
	
	while (str[i])
		i++;
	return i;
}
int main()
{
	char str[13];
	int len;

	scanf("%s",str);
	len = strlen(str);
	
	for(int i= 0; i< len - 1; i++)
	{
		for (int j=0; j<len - i - 1; j++)
		{
			if (str[j] < str[j + 1])
				char_swap(&str[j], &str[j + 1]);
		}
	}
	printf("%s\n",str);
}
