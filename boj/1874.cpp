#include <bits/stdc++.h>


using namespace std;


int	main()
{
    std::ios_base::sync_with_stdio(false);
    int n, max = 1, flag = 0;
    vector<int> result;
    cin >> n;
    stack<int> stk;
    int num;
    while (n--) {
        cin >> num;
        while (true) {
            if (max <= num) {
                stk.push(max++);
                result.push_back(1);
            }
            else if (num == stk.top()) {
                stk.pop();
                result.push_back(0);
                break;
            }
            else if (stk.top() < max) {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag) {
        cout <<"NO";
        return 0;
    }
    for(int i : result) {
        if (i)
            cout << "+"<<"\n";
        else
            cout << "-"<<"\n";
    }
    return 0;
}