#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
	int size = s.length();
	vector<string> wholestr;
	wholestr.push_back("");
	for (int i = 1; i <= size; i++)//문자열 단위길이
	{	
		wholestr.push_back("");
		int num = 1;
		for (int j = 0; j < size ; j=j+i)//문자열 내부 돌기
		{
			
			string str1 = "";
			string str2 = "";

			for (int k = 0; k < i; k++) {
				if ((k + j) <= size)
				{
					str1 = str1 + s[k + j];
					
				}
				else { ; }
				if ((k + j + i) <= size) {
					if ((int)s[k + j + i] < 97 || (int)s[k + j + i] > 122) {
						;
					}
					else {
						str2 = str2 + s[k + j + i];
					}
				}
				else { ; }
			}
			if (str1 == str2) {
				//cout << "같은 str1 : "  << str1 << " str2 :" << str2<< "j : " <<j<< endl;
				num++;
				
			}
			else {//다르면
				//cout << "다른 str1 : " << str1 << " str2 :" << str2 << "j : " << j << endl;
				//cout << str2 << "|" <<endl;
				string intTOstr = to_string(num);
				if (num == 1)
				{
					;
				}
				else {
					wholestr[i] += intTOstr;
				}
				
				wholestr[i] += str1;
				//if (num == 1) {
				//	wholestr += str1;
				//}
				//else {
				//	string intTOstr = to_string(num);
				//	cout << "\nint : " << intTOstr << endl;
				//	wholestr += intTOstr;
				//	wholestr += str1;
				//}
				if (str1.length() > str2.length()) {
					//str2 가 마지막 문자라는 증거
					//wholestr += str1;
					if (str2 != "" || str2 != " " || str2 != "  ") {
						wholestr[i] += str2;
					}
					break;
				}
				num = 1;
			}
			
			//cout << str1 << " + " << str2 << endl;
			
		}
		string str = wholestr[i];
		str.erase(remove(str.begin(), str.end(), ' '), str.end());
		//wholestr[i].erase(remove(wholestr[i].begin(), wholestr[i].end(), ' '))
		//cout << "wholestr :" << i << ":"<<  wholestr[i]  << "size : " << wholestr[i].length()<< endl;
	}

	int answer = wholestr[1].length();
	for (int i = 1; i < wholestr.size(); i++) {
		if (answer > wholestr[i].length()) answer = wholestr[i].length();
	}
	//cout << answer << endl;
	return answer;
}
int main() {

	cout << solution("aabbaccc");

	cout << solution("ababcdcdababcdcd");

	cout << solution("abcabcdede");

	cout << solution("abcabcabcabcdededededede");

	cout << solution("xababcdcdababcdcd");
	
}	