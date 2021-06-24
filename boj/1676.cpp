#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int count = 0;

	cin>>n;
	
	//5로 나뉠 때 마다 + 1
	//25는 5^2 이므로 + 2
	//125는 5^3 이므로 + 3
	while(n > 0)
	{
		if (n % 5 ==0)
		{
			if (n % 25 == 0)
			{
				if (n % 125 == 0)
					count++;
				count++;
			}
			count++;
		}
		n--;
	}
	cout<<count;

}
