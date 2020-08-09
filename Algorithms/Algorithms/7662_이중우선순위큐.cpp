#include <iostream>
#include <vector>
#include<queue>
#include <string>
//https://jaimemin.tistory.com/997
//참고하기...
//실패상태 -> 시간초과
using namespace std;

int main() {
	

	int t, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		priority_queue<int, vector<int>, greater<int>> gpq;
		cin >> k;
		for (int j = 0; j < k; j++) {
			string s;
			int num;
			cin >> s >> num;
			if (s == "I") {
				gpq.push(num);
			}
			else if (s == "D") {
				if (gpq.empty()) {
					;
				}
				else {
					if (num == -1) {
						gpq.pop(); //최소값 삭제
					}
					if (num == 1) {
						//최대값 삭제
						vector<int> v;
						int size = gpq.size();
						for (int l = 0; l < size; l++) {
							v.push_back(gpq.top());
							gpq.pop();
						}
						for (int l = 0; l < v.size()-1; l++) {
							gpq.push(v[l]);
						}
						
						/*
						priority_queue<int, vector<int>, less<int>> lpq;
						for (int l = 0; l < gpq.size(); l++) {
							lpq.push(gpq.top());
							gpq.pop();
						}
						lpq.pop();
						for (int l = 0; l < lpq.size(); l++) {
							gpq.push(lpq.top());
							lpq.pop();
						}*/
					}
				}
				
			}
		}
		if (gpq.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			int min = gpq.top();
			vector <int>v;
			int size = gpq.size();
			for (int l = 0; l < size; l++) {
				v.push_back(gpq.top());
				gpq.pop();
			}
			int max = v[v.size() - 1];
		
			cout << max << " " << min << '\n';
			
		}

	}

	return 0;
}