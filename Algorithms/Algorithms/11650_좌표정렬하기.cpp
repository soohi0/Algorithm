#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		pair<int, int> inputNum;
		scanf("%d %d", &inputNum.first, &inputNum.second);
		pq.push(inputNum);
	}
	for (int i = 0; i < N; i++) {
		pair<int, int> num = pq.top();
		printf("%d %d\n", num.first, num.second);
		pq.pop();
	}



}