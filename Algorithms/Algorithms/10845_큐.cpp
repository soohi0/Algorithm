//https://www.acmicpc.net/problem/10845
//STL È°¿ë
#include <iostream>
#include <vector>
#include<queue>
#include <string>

using namespace std;

int main() {
	queue<int> q;

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		string str = "";
		cin >> str;
		if (str == "push") {
			int n;
			cin >> n;
			q.push(n);
		}
		else if (str == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
			}
		}
		else if (str == "back") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.back() << '\n';
			}
		}
		else if (str == "size") {
			cout << q.size() << '\n';
		}
		else if (str == "empty") {
			if (q.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "pop") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}

		}
	}
}


