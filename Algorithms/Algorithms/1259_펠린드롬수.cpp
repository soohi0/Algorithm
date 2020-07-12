#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isSame(string s) {
	for (int i = 0; i < (int)s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}
int main() {
	int endNum = 0;
	vector<bool> v;
	
	while (true) {
		
		string inputNum = "s";
		cin >> inputNum;
		if (inputNum == "0") {
			break;
		}
		v.push_back(isSame(inputNum));
		
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == true) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';

		}
	}
	return 0;
}