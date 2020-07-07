//1929 소수구하기

#include <iostream>
#include <stdio.h>

using namespace std;
void printPrimeNum(int m, int n, bool * yorn);

int main() {
	
	int M, N;
	cin >> M >> N; //M시작 ~ N끝

	bool * primeNum = new bool[N+1];
	for (int i = 0; i <= N; i++) {
		primeNum[i] = true;
	}
	primeNum[1] = false; // 1은 소수 아님
	printPrimeNum(M, N, primeNum);

	for (int i = M; i <= N; i++) {
		if (primeNum[i] == true) {
			printf("%d\n", i);
		}
	}
	return 0;

}
void printPrimeNum(int m, int n, bool* yorn)//int* 결과 바뀜
{
	//for (int i = 2; i < n; i++) {
	//	for (int j = 0; j < n - (m - 1); j++) {
	//		if (nums[j] == 0) continue;
	//		if (nums[j] % i == 0) {
	//			//나누어 떨어짐
	//			if (nums[j] != i) {//자신 제외
	//				nums[j] = 0;
	//			}
	//		}
	//	}
	//}
	//이렇게 하면 나머지 연산이 시간을 많이 잡아먹어 시간초과가 뜨게 된다

	//에라토스테네스의 체를 이용
	//2의 배수~N의 배수는 소수가 아니라는 의미의 false, 처음 초기화는 모두 true로 해준다
	
	for (int i = 2; i <= n; i++) {
		for (int j = 2; i * j <= n; j++) {
			yorn[i * j] = false;
		}
	}
}