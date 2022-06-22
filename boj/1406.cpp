#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

list<char> editor;

int	main()
{
	int t;
	int size = 0;
	string input;

	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		editor.push_back(input[i]);
		size++;
	}
	cin >> t;
	list<char>::iterator cursor;
	cursor = editor.end();

	for (int i = 0; i < t; i++) {
		cin >> input;
		if (input == "P") {
			cin >> input;
			editor.insert(cursor, input[0]);
			size++;
		}
		else if (input == "L") {
			if (cursor != editor.begin()) {
				cursor--;
				size--;
			}
		}
		else if (input == "D") {
			if (cursor != editor.end()) {
				cursor++;
				size++;
			}
		}
		else if (input == "B") {
			if (cursor != editor.begin()){
				cursor--;
				cursor = editor.erase(cursor);

			}
		}
	}
	for (cursor = editor.begin(); cursor != editor.end(); cursor++) {
		cout << *cursor;
	}
	return 0;
}