#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;

int result;
int arr[9];
int visited[9];
int tmp_arr[9];
vector <int>v;
int n;


//20 1 15 8 4 10
void recur(int i)
{

        if(i == (n + 1))
        {
		int tmp = 0;
		for(int j=0; j<v.size() - 1; j++)
			tmp += abs(v[j] - v[j + 1]);
		if(result < tmp)
			result = tmp;
		return;
	}


        for(int j=1; j<=n; j++)
        {
		if(visited[j])
			continue;
		visited[j] = 1;
		//tmp_arr[j] = arr[j];
		v.push_back(arr[j]);
		recur(i + 1);
		visited[j] = 0;
		//tmp_arr[j] = 0;
		v.pop_back();
        }

}

int main()
{
        scanf("%d", &n);

        for(int i=1; i<=n; i++)
                scanf("%d", &arr[i]);

        recur(1);
        cout<<result;
        return 0;
}
