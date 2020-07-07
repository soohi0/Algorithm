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
	} �ش� Ž���� ��� log(n^2 )�̱⿡ �ð� �ʰ��� �߻��Ѵ�.
	���� lowerbound �� upper_bound �� �̿��ؾ��Ѵ�.
	lower_bount �� ���Ѽ�. ã���� �ϴ� ���ڿ� ���ų� ū ���ڰ� ��ġ�� idx�� ����.
	1 2 4 6 6 6 7 �϶� 6�� ������ ��ġ�� 4 �� idx���� 3�ε� 4�� ����

	upper_bound �� ���Ѽ�. Ű������ ū ������ ��ġ ��ȯ. 6�̸� 7�� ��ġ 7(idx�� 6)����
	���� upper_bound - lower_bound �ϸ� �ߺ��Ǵ� ������ ���� �ִٴ� �Ŵ�
	���ϴ� 6�� cnt���� 3�ε�
	upper_bound = 7
	lower_bound = 4
	upper_bound - lower_bound = 3 �̹Ƿ� 

	�ش� �Լ��� algorithm �� ������ ���ĵ� ���¿����� ����ȴ�.
	
	*/
	
	for (int i = 0; i < M; i++) {
		auto low = lower_bound(sangen.begin(), sangen.end(), card[i]);
		auto up = upper_bound(sangen.begin(), sangen.end(), card[i]);
		
		printf("%d ", up - low);
	}

	return 0;
}