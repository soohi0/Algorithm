//1929 �Ҽ����ϱ�

#include <iostream>
#include <stdio.h>

using namespace std;
void printPrimeNum(int m, int n, bool * yorn);

int main() {
	
	int M, N;
	cin >> M >> N; //M���� ~ N��

	bool * primeNum = new bool[N+1];
	for (int i = 0; i <= N; i++) {
		primeNum[i] = true;
	}
	primeNum[1] = false; // 1�� �Ҽ� �ƴ�
	printPrimeNum(M, N, primeNum);

	for (int i = M; i <= N; i++) {
		if (primeNum[i] == true) {
			printf("%d\n", i);
		}
	}
	return 0;

}
void printPrimeNum(int m, int n, bool* yorn)//int* ��� �ٲ�
{
	//for (int i = 2; i < n; i++) {
	//	for (int j = 0; j < n - (m - 1); j++) {
	//		if (nums[j] == 0) continue;
	//		if (nums[j] % i == 0) {
	//			//������ ������
	//			if (nums[j] != i) {//�ڽ� ����
	//				nums[j] = 0;
	//			}
	//		}
	//	}
	//}
	//�̷��� �ϸ� ������ ������ �ð��� ���� ��ƸԾ� �ð��ʰ��� �߰� �ȴ�

	//�����佺�׳׽��� ü�� �̿�
	//2�� ���~N�� ����� �Ҽ��� �ƴ϶�� �ǹ��� false, ó�� �ʱ�ȭ�� ��� true�� ���ش�
	
	for (int i = 2; i <= n; i++) {
		for (int j = 2; i * j <= n; j++) {
			yorn[i * j] = false;
		}
	}
}