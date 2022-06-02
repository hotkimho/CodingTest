#include <bits/stdc++.h>
using namespace std;

int visited[1001];
int arr[1001];
int result, n;

int main(void) {
    int m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i < n; i++)
		for (int j = i; j <= n; j++)
			if (arr[i] != arr[j])
				result++;
	cout << result;
}