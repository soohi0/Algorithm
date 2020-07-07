//1929 소수구하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
void printPrimeNum(int n, int& cnt, bool * yorn, int * nums);

int main() {

	int N;
	int count = 0;// 소수 개수
	scanf("%d", &N);
	int * nums = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}

	bool * primeNum = new bool[1000001];
	for (int i = 0; i <= 1000; i++) {
		primeNum[i] = true;
	}
	primeNum[1] = false; //1 소수 아님

	printPrimeNum(N, count, primeNum, nums);

	printf("%d", count);
	return 0;

}
void printPrimeNum( int n, int& cnt, bool* yorn, int* nums)//int* 결과 바뀜
{
	for (int i = 2; i <= 1000; i++) {
		for (int j = 2; i * j <= 1000; j++) {
			yorn[i * j] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		if (yorn[nums[i]] == true)
		{
			printf("%d", nums[i]);
			cnt++;
		}
	}
}