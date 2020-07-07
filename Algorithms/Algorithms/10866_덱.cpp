//https://www.acmicpc.net/problem/10866
//STL È°¿ë
#include <iostream>
#include <vector>
#include<deque>
#include <string>
using namespace std;

int main() {
	deque<int> deq;

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		string str = "";
		cin >> str;
		if (str == "push_back") {
			int n;
			cin >> n;
			deq.push_back(n);
		}
		else if (str == "push_front") {
			int n;
			cin >> n;
			deq.push_front(n);
		}
		else if (str == "front") {
			if (deq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << deq.front() << '\n';
			}
		}
		else if (str == "back") {
			if (deq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << deq.back() << '\n';
			}
		}
		else if (str == "size") {
			cout << deq.size() << '\n';
		}
		else if (str == "empty") {
			if (deq.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "pop_front") {
			if (deq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << deq.front() << '\n';
				deq.pop_front();
			}

		}
		else if (str == "pop_back") {

			if (deq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << deq.back() << '\n';
				deq.pop_back();
			}

		}
	}
}


