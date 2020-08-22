//string call by reference 사용
//string functionname (string & name)
#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
string devideU(string &inputS);

bool IsRIght(string u)
{
	bool isright = true;
	stack<char> stk;
	vector<char> vc;

	//올바른지 아닌지 확인
	for (int i = 0; i < u.length(); i++)
	{
		stk.push(u[i]);
	}

	while (!stk.empty()) {
		char c = stk.top();

		stk.pop();
		if (c == ')') {
			vc.push_back(')');

		}
		else if (c == '(') {
			if (vc.empty())
			{
				return false;
			}
			else {
				vc.pop_back();
			}
		}

	}
	return true;
}
string recursion(string inputS)
{
	if (inputS == "")
	{
		return "";
	}
	string u;
	string v = inputS;
	//string realU = "";
	u = devideU(v);
	string newu = "";

	//cout << "u : " << u;
	//cout << "v : " << v;

	if (IsRIght(u))
	{
		newu += u;
		newu += recursion(v);
	}
	else {
		newu = "(";
		newu += recursion(v);
		newu += ")";

		string cutU = "";
		//앞뒤 짜름
		for (int i = 1; i < u.length()-1; i++)
		{
			cutU += u[i];
		}
		u = cutU;
		for (int i = 0; i < u.length(); i++)
		{
			if (u[i] == '(')
			{
				u[i] = ')';
			}
			else if (u[i] == ')')
			{
				u[i] = '(';
			}
		}
		newu += u;
	}

	return newu;


}
string devideU(string &inputS)
{
	string u = "";
	int leftcnt = 0;
	int rightcnt = 0;
	int size = inputS.length();
	string v = inputS;
	for (int i = 0; i < size; i += 2)
	{
		if (leftcnt > 0 && rightcnt > 0)
		{
			if (leftcnt == rightcnt)
			{
				break;
			}
		}

		if (inputS[i] == '(' && inputS[i + 1] == '(')
		{
			leftcnt += 2;
		}
		else if (inputS[i] == ')' && inputS[i + 1] == ')')
		{
			rightcnt += 2;
		}
		else if (inputS[i] != inputS[i + 1])
		{
			leftcnt++;
			rightcnt++;
		}
		else { ; }
		u = u + inputS[i] + inputS[i + 1];
	}
	inputS = "";
	for (int i = leftcnt + rightcnt; i < size; i++)
	{
		inputS += v[i];
	}
	return u;
}
string solution(string p) {
	string answer = "";
	bool isright;
	isright = IsRIght(p);

	if (isright)
	{
		//cout << "right" << endl;
		answer = p;
	}
	else {
		//cout << "wrong" << endl;
		answer = recursion(p);
		//u = devideU(v);
		//recursion
		//cout << "v : " << v << endl;
	}
	//cout << "answer : " << answer;
	return answer;
}

int main()
{
	
	solution("()))((()");
}