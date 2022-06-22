#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
    int n;
    int result = 0;

    cin >> n;
    while (n--) {
        string str;
        stack<char> stk;
        cin >> str;
        if (str.size() % 2 == 1)
            continue;
        
        for (int i = 0; i < str.size(); i++) {
            if (stk.size() > 0 && stk.top() == str[i]) {
                stk.pop();
                continue;
            }
            else {
                stk.push(str[i]);
            }
        }
        if (stk.size() == 0)
            result++;
    }
    cout << result;
}
