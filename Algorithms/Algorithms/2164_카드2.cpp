#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	queue <int> q;
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	int toback;
	while (!q.empty()) {
		q.pop();
		if (q.empty()) break;
		toback = q.front();
		q.push(toback);
		q.pop();

	}
	printf("%d", toback);

	return 0;
}