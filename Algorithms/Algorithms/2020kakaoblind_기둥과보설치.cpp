#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>
#include<stack>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;


map<tuple<int, int, int>, int> ress;
bool cmp(vector<int> v1, vector<int> v2) {
	if (v1[0] == v2[0]) {
		if (v1[1] == v2[1]) {
			return v1[2] < v2[2];
		}
		return v1[1] < v2[1];
	}
	return v1[0] < v2[0];
}

bool check() {
	for (auto r : ress) {
		int x, y, a; tie(x, y, a) = r.first;

		if (a == 0) {//기둥
			//기둥이 올바르게 있는제 확인
			if (y == 0 || ress.count(make_tuple(x - 1, y, 1)) || ress.count(make_tuple(x, y, 1)) || ress.count(make_tuple(x, y - 1, 0)))
				continue;
			else
				return false;
		}

		else if (a == 1) {//보
			//보가 올바르게 있는지 확인
			if (ress.count(make_tuple(x, y - 1, 0)) || ress.count(make_tuple(x + 1, y - 1, 0)) || (ress.count(make_tuple(x - 1, y, 1)) + ress.count(make_tuple(x + 1, y, 1)) == 2))
				continue;
			else
				return false;
		}
	}

	return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	for (auto build : build_frame) {
		tuple<int, int, int> b = make_tuple(build[0], build[1], build[2]);
		int toggle = build[3];

		//명령문 그냥 실행
		if (toggle == 1) {//추가
			ress[b] = true;

			if (check() == false) {
				ress.erase(b);
			}
		}
		else if (toggle == 0) {//삭제
			ress.erase(b);

			if (check() == false) {
				ress[b] = true;
			}
		}

	}


	for (auto res : ress) {
		int x, y, a; tie(x, y, a) = res.first;
		vector<int> r = { x,y,a };
		answer.push_back(r);
	}
	//조건에 맞게 정렬
	sort(answer.begin(), answer.end(), cmp);

	return answer;
}
int main()
{
	vector<vector<int>> vv = {
		{1,0,0,1},
		{1, 1, 1, 1},
		{2, 1, 0, 1},
		{2, 2, 1, 1},
		{5, 0, 0, 1},
		{5, 1, 0, 1},
		{4, 2, 1, 1},
		{3, 2, 1, 1},

	};
	solution(5, vv);
}
