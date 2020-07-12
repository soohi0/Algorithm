//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	int N;
//	cin >> N;
//	
//	vector<string> * v = new vector<string> [20000];
//	for (int i = 0; i < N; i++) {
//		string s;
//		cin >> s;
//		bool isSame = false;
//		for (int j = 0; j < v[s.size()-1].size(); j++) {
//			
//			if (s == v[s.size() - 1][j]) {
//				isSame = true;
//			}
//		}
//		if (!isSame) {
//			v[s.size() - 1].push_back(s);
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		if (!(v[i].empty())) {
//			sort(v[i].begin(), v[i].end());
//			for (int j = 0; j < v[i].size(); j++) {
//				cout << v[i][j] << '\n';
//			}
//		}
//	}
//		
//	
//} //이 코드가 왜 안되는지 모르겠음....
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool compare(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else {
		return a.size() < b.size();
	}
}

int main() {
	int N;
	cin >> N;
	string tmp;

	vector<string> v;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		if (tmp == v[i])continue;
		cout << v[i] << '\n';
		tmp = v[i];
	}
	return 0;




}