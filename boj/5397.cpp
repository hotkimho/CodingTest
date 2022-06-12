#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;


int	main()
{
	int t;
	int size = 0;
	string input;

	cin >> t;
	list<char>::iterator cursor;

	for (int i = 0; i < t; i++) {
		list<char> L = {};
		cursor = L.begin();
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			if (input[j] == '-') {
				if (cursor != L.begin()){
					cursor--;
					cursor = L.erase(cursor);
				}
			}
			else if (input[j] == '<') {
				if (cursor != L.begin()) {
					cursor--;
				}
			}
			else if (input[j] == '>') {
				if (cursor != L.end()) {
					cursor++;
				}
			}
			else {
				L.insert(cursor, input[j]);
			}
		}
		for (cursor = L.begin(); cursor != L.end(); cursor++) {
			cout << *cursor;
		}
		cout<<endl;
	}

	return 0;
}