#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	
	//freopen("input.txt", "r", stdin);
	while (1) {
		string str;
		getline(cin , str);
		if (str == ".")
			break;
		stack<char> stk;
		int isResult = 1;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') 
                stk.push(str[i]);
            
			if (str[i] == ')' || str[i] == ']') {
				if (stk.size() <= 0) {
					isResult = 0;
					break;
				}
				if (stk.top() == '(' && str[i] == ']') {
                    isResult = 0;
                    break;
                }
                else if (stk.top() == '[' && str[i] == ')') {
                    isResult = 0;
                    break;
                }
				stk.pop();
			}
		}
		if (stk.size() != 0)
			isResult = 0;
		if (isResult)
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}
}
