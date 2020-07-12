#include <iostream>

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main()
{
	int n, m;

	cin >> n >> m;

	cout << gcd(n, m) << "\n" << lcm(n, m);
	

}
int gcd(int a, int b) {
	//최대공약수를 구할 때 유클리드 호제법을 이용한다
	//a가 큰수여야함
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}