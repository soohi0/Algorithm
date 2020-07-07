#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool TorF(int* n, int m);
int Nnum[100001];

	int N;
int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &Nnum[i]);
	}
	sort(Nnum, Nnum+N);

	int M;
	scanf("%d", &M);
	vector<int> Mnum;
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		Mnum.push_back(num);
	}
	for (int i = 0; i < M; i++) {
		printf("%d ", TorF(Nnum, Mnum[i]));
	}
}
bool TorF(int *n, int m) {
	//이진탐색해야한다.
	int start = 0;
	int end = N - 1;
	while (end - start >= 0) {
		int mid = (end + start) / 2;
		if (n[mid] == m) {
			return true;
		}
		else if (n[mid] < m) {
			start = mid+1;
		}
		else {
			end = mid-1;
		}
	}
	return false;
}
