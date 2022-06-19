#include <bits/stdc++.h>


using namespace std;


int	main()
{
    std::ios_base::sync_with_stdio(false);
    int n, max = 1, flag = 0;
    vector<int> result;
    cin >> n;
    stack<int> stk;
    while (n--) {
        if (max > stk.top() && stk.size() > 0) {
            flag = 1;
            break;
        }
        if (max == stk.top() && stk.size() > 0)
        {
            result.push_back(0);
            stk.pop();
        }
        stk.push(max++);
        result.push_back(1);
    }
    cout << flag << endl;
    for(int i = 0; i < result.size(); i++)
            cout << result[i]<<" ";
	return 0;
}