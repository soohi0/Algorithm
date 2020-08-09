#include <string>
#include <vector>
#include <iostream>

using namespace std;

//int n, m;
//
//bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
//	bool answer = false;
//
//	//���� ä������ ���簢 �ּ� ���� ���ϱ�
//	 // 0�� �ִ� ������ �ּ� �ִ� �ε��� ���ϱ�
//	int keym = key.size();
//	int lockn = lock.size();
//
//	int up, down, left, right;
//
//	for (int i = lockn - 1; i >= 0; i--) {
//		for (int j = 0; j < lockn; j++) {
//			if (lock[i][j] == 0) {
//				up = i;
//				break;
//			}
//		}
//	}
//	cout << "up :" << up << endl;
//	for (int i = 0; i < lockn; i++) {
//		for (int j = 0; j < lockn; j++) {
//			if (lock[i][j] == 0) {
//				down = i;
//				break;
//			}
//		}
//	}
//	cout << "down :" << down << endl;
//	for (int i = 0; i < lockn; i++) {
//		for (int j = 0; j < lockn; j++) {
//			if (lock[j][i] == 0) {
//				left = i;
//				break;
//			}
//		}
//	}
//	cout << "left :" << left << endl;
//	for (int i = lockn-1; i >=0; i--) {
//		for (int j = 0; j < lockn; j++) {
//			if (lock[j][i] == 0) {
//				right = i;
//				break;
//			}
//		}
//	}
//	cout << "right :" << right << endl;
//	int garolength = right - left + 1;
//	int serolength = up - down + 1;
//	int newlockn = 0;
//
//	if (garolength != serolength) {
//		if (garolength > serolength) {
//			newlockn = garolength;
//		}
//		else {
//			newlockn = serolength;
//		}
//	}
//	else {
//		newlockn = garolength;
//	}
//
//
//	//���� �� �ּ� ������ m * m ���� ũ�ٸ� false ����
//
//	//�ƴϸ�
//
//	//�ּҸ����� ����+Ű���ٰ�  ���������� 90, 180, 270 ȸ��, ���� 90, 180, 270 ȸ���� ä�� �̵��Ͽ� ���纸��
//
//	return answer;
//}
/*
3 3
0 0 0
1 0 0
0 1 1
1 1 1
1 1 0
1 0 1
*/


bool solution(vector<vector<int>> key, vector<vector<int>> lock);
int insert(int x, int y, int N, vector<vector<int>> board, vector<vector<int>> key);
vector<vector<int>> rotate(vector<vector<int>> key);

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int N = lock.size(), M = key.size();
	vector<vector<int>> board(2 * M + N - 2, vector<int>(2 * M + N - 2, 0));

	//put lock on the board
	for (int ny = M - 1, a = 0; ny < M - 1 + N; ny++, a++) {
		for (int nx = M - 1, b = 0; nx < M - 1 + N; nx++, b++) {
			board[ny][nx] = lock[a][b];
		}
	}

	//put key on board with rotation
	for (int i = 0; i < M + N - 1; i++) {
		for (int l = 0; l < M + N - 1; l++) {
			vector<vector <int>> nextKey = key;

			for (int d = 0; d < 4; d++)
			{
				if (insert(l, i, N, board, nextKey) == 0) return true;
				nextKey = rotate(nextKey);
			}
		}
	}
	return false;
}

//rotate function, just put element start from side, ���� �Ʒ�����
vector<vector<int>> rotate(vector<vector<int>> key) {
	int s = key.size();
	vector<vector<int>> result(s, vector<int>(s, 0));

	for (int l = 0, a = 0; l < s; l++, a++) {
		for (int i = s - 1, b = 0; i >= 0; i--, b++) {
			result[a][b] = key[i][l];
		}
	}
	return result;
}

//insert and count function, if it isn't fit then return -1, or count the 1 in lock board to check if it fits well
int insert(int x, int y, int N, vector<vector<int>> board, vector<vector<int>> key) {
	int M = key.size();

	//��Ʈ�������� �̿�
	for (int ny = y, a = 0; ny < y + M; ny++, a++) {
		for (int nx = x, b = 0; nx < x + M; nx++, b++) {
			board[ny][nx] = board[ny][nx] ^ key[a][b];
			if (!board[ny][nx] && key[a][b]) return -1;
		}
	}

	//�ش� �ڹ��谡 �� ���¾Ҵ��� 1�� ������ count
	int count = 0;
	for (int ny = M - 1; ny < M + N - 1; ny++) {
		for (int nx = M - 1; nx < N + M - 1; nx++) {
			if (!board[ny][nx]) count++;
		}
	}
	return count;

}
int main()
{/*
	cin >> n >> m;
	vector<vector<int>> key;
	for (int i = 0; i < m; i++) {
		vector<int> v;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		key.push_back(v);
	}
	vector<vector<int>> lock;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		lock.push_back(v);
	}

	cout << solution(key, lock);*/
	vector<vector <int>> key = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
	vector<vector <int>> lock = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
	cout << solution(key, lock) << endl;

	return 0;

}
void printArr(vector<vector<int>> key, vector<vector<int>> lock)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << key[i][j] << " ";
		}
		cout << endl;
	}
	cout << "=================================" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << lock[i][j] << endl;

		}
		cout << endl;
	}
	cout << "==================================" << endl;
}