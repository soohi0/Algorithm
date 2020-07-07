//https://www.acmicpc.net/problem/10845
//STL È°¿ë
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {

	stack<int> stk;
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		string str = "";
		cin >> str;
		if (str == "push") {
			int n;
			cin >> n;
			stk.push(n);
		}
		else if (str == "top") {
			if (stk.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << stk.top() << '\n';
			}
		}
		else if (str == "size") {
			cout << stk.size() << '\n';
		}
		else if (str == "empty") {
			if (stk.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "pop") {
			if (stk.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << stk.top() << '\n';
				stk.pop();
			}

		}
	}
}


