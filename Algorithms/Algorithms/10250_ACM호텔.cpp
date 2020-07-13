#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	vector <int> v;
	for (int i = 0; i < t; i++) {
		int h, w, n;//h = Ãþ¼ö, w= ¹æ¼ö, n ¼Õ´Ô ¿Â¼ø¼­
		cin >> h >> w >> n;
		int floor;
		int room;
		if (n%h == 0) {
			floor = h;
			room = n / h;
		}
		else {
			floor = n % h;
			room = n / h + 1;
		}
		int roomNum = floor * 100 + room;
		v.push_back(roomNum);
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}
