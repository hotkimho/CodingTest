#include <bits/stdc++.h>

using namespace std;


int	main()
{
    std::ios_base::sync_with_stdio(false);
    int n;
    queue<int> que;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        que.push(i);
    }
    while (que.size() > 1) {
        que.pop();
        if (que.size() <= 1)
            break;
        int data = que.front();
        que.push(data);
        que.pop();
    }
    cout << que.front();
    que.pop();
    return 0;
}