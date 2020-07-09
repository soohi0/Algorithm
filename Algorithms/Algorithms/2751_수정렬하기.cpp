#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	int N; 
	scanf("%d", &N);

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		pq.push(num);
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", pq.top());
		pq.pop();
	}

}