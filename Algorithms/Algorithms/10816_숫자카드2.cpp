#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	vector<int>sangen;
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		sangen.push_back(num);
	}
	sort(sangen.begin(), sangen.end());

	int M;
	scanf("%d", &M);
	vector<int> card;
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		card.push_back(num);
	}

	
	/*for (int i = 0; i < M; i++) {
		int count = 0;
		for (int j = 0; j < N; j++) {
			if(card[i] == sangen[j]) {
				count++;
			}
		}
		card[i] = count;
	} 해당 탐색의 경우 log(n^2 )이기에 시간 초과가 발생한다.
	따라서 lowerbound 와 upper_bound 를 이용해야한다.
	lower_bount 는 하한선. 찾고자 하는 숫자와 같거나 큰 숫자가 위치한 idx를 리턴.
	1 2 4 6 6 6 7 일때 6을 넣으면 위치는 4 즉 idx값은 3인데 4를 리턴

	upper_bound 는 상한선. 키값보다 큰 최초의 위치 반환. 6이면 7의 위치 7(idx는 6)리턴
	따라서 upper_bound - lower_bound 하면 중복되는 개수를 구할 있다는 거다
	원하는 6의 cnt값은 3인데
	upper_bound = 7
	lower_bound = 4
	upper_bound - lower_bound = 3 이므로 

	해당 함수는 algorithm 에 있으며 정렬된 상태에서만 적용된다.
	
	*/
	
	for (int i = 0; i < M; i++) {
		auto low = lower_bound(sangen.begin(), sangen.end(), card[i]);
		auto up = upper_bound(sangen.begin(), sangen.end(), card[i]);
		
		printf("%d ", up - low);
	}

	return 0;
}