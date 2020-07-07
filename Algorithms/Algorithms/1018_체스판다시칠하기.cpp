//1018 체스판 다시 칠하기
//성공
//#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void printBoard(vector<string> b);
void cmpWB(vector<string> board);
void cmpBW(vector<string> board);

int N, M = 0;
int minNum = 64;
string WB[8] = {"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW"
};
string BW[8] = {
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB"
};

int main() {

	vector <string> inputboard;

	cin >> N >> M;//N 세로Y, M 가로X

	for (int i = 0; i < N; i++) {
		inputboard.push_back("");
		for (int j = 0; j < M; j++) {
			char ch;
			cin >> ch;
			inputboard[i] += ch;
		}
	}

	cmpWB(inputboard);
	cmpBW(inputboard);
	cout  << minNum << endl;
	//printBoard(inputboard);
	//Sleep(10000);

	return 0;
}
void printBoard(vector<string> b) {
		cout << "==========================" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << b[i][j];
		}
		cout << endl;
	}
}
void cmpWB(vector<string> board) {
	int wrongwords = 0;
	int x = 7;
	int y = 7;//맨 끝 인덱스
	int idxX = 7; 
	int idxY = 7;
	while ((x <= M-1) &&(y <= N-1)) {
		//cout <<"dddd : " <<WB[idxY][idxX] << endl;
		for (int i = y; i >= y - 7; i--) {
			for (int j = x; j >= x - 7; j--) {
				if (board[i][j] == WB[idxY][idxX]) {
					//cout << "wb : "<<WB[idxY][idxX] << endl;
				}
				else {
					wrongwords++;
				}
				idxX--;
			}
			idxY--;
			idxX = 7;
		}
		if (wrongwords < minNum) {
			minNum = wrongwords;
		}
		wrongwords = 0;
		if (x + 1 > M - 1) {
			if (y + 1 > N - 1) {
				break;
			}
			else {
			//다음줄로 내려감
				y++;
				x = 7;
			}
		}
		else {
			x++;
		}
		idxX = 7;
		idxY = 7;
	}

}
void cmpBW(vector<string> board) {
	int wrongwords = 0;
	int x = 7;
	int y = 7;//맨 끝 인덱스
	int idxX = 7;
	int idxY = 7;
	while ((x <= M - 1) && (y <= N - 1)) {
		//cout <<"dddd : " <<WB[idxY][idxX] << endl;
		for (int i = y; i >= y - 7; i--) {
			for (int j = x; j >= x - 7; j--) {
				if (board[i][j] == BW[idxY][idxX]) {
					//cout << "wb : "<<WB[idxY][idxX] << endl;
				}
				else {
					wrongwords++;
				}
				idxX--;
			}
			idxY--;
			idxX = 7;
		}
		if (wrongwords < minNum) {
			minNum = wrongwords;
		}
		wrongwords = 0;
		if (x + 1 > M - 1) {
			if (y + 1 > N - 1) {
				break;
			}
			else {
				//다음줄로 내려감
				y++;
				x = 7;
			}
		}
		else {
			x++;
		}
		idxX = 7;
		idxY = 7;
	}
}
