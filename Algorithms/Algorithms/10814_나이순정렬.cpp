#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

struct Id {
	int age;
	string name;
	int order;
};
bool vectorcmp(Id  i1, Id  i2) {
	if (i1.age < i2.age) {
		return true;
	}
	else if (i1.age == i2.age) {
		return i1.order < i2.order;
	}
	else {
		return false;
	}
}


int main() {
	int N;
	scanf("%d", &N);
	vector <Id> persons(N);
	
	for (int i = 0; i < N; i++) {
		//Id person;
		//cin >> person.age >> person.name;
		cin >> persons[i].age >> persons[i].name;
		//scanf("%d %s", &persons[i].age, &persons[i].name);
		//person.order = i;
		persons[i].order = i;
		//persons.push_back(person);
	}
	
	//왜인지 모르겠지만 내가 만든 id 구조체를 하나 만들고 거기에 데이터를 넣고 그거를 벡터에 pushback해주면 안된다.
	//scanf떄문인가 해서 cin 으로 바꿔서 했는데 흠 안된다...


	sort(persons.begin(), persons.end(), vectorcmp);

	for (int i = 0; i < N; i++) {
		cout << persons[i].age << " " <<persons[i].name << "\n";
		//printf("%d %s \n", persons[i].age, persons[i].name.c_str());
		//printf 에서 %s 를 해주게 되면 string 형태를 char* 문자열 형태로 바꿔주어야 출력이 된다.
		//cout의 경우는 그냥 해줘도 되는데 printf는 바꿔주는 .c_str()를 해주어야 한다.
		//but 왜인지 모르겠지만 이 경우에 문자가 짤린다..그래서 그냥 cin과 cout으로 해주기로 한다.

	}
	
	return 0;
}

