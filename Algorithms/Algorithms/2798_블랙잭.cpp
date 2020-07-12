//Memoization 이용
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> v;
	priority_queue<int, vector<int>, less<int>> pq;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() - 2; i++) {
		vector < pair<int, int> > partSum;

		for (int j = i + 1; j < n - 1; j++) {
			pair <int, int> p;
			p.first = v[i] + v[j];
			p.second = j + 1; // 세번째 더해야 할 수 idx 최소 수
			partSum.push_back(p);
		}
		
		for (int j = 0; j < partSum.size(); j++) {
			for (int k = partSum[j].second; k < n; k++) {
				int sum = partSum[j].first + v[k];
				if (sum <= m) {
					pq.push(sum);
				}
			}

		}

		
	}

	cout << pq.top();
	//1 2 3
	//1 2 4
	//1 2 5
	//1 2 6
	//1 3 4
	//1 3 5
	//1 3 6
	//1 4 5
	//1 4 6
	//1 5 6
	//2 3 4
	//2 3 5
	//2 3 6
	//2 4 5
	//2 4 6
	//2 5 6
	//3 4 5
	//3 4 6
	//3 5 6
	//4 5 6

	return 0;
}