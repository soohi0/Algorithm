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
	
	//������ �𸣰����� ���� ���� id ����ü�� �ϳ� ����� �ű⿡ �����͸� �ְ� �װŸ� ���Ϳ� pushback���ָ� �ȵȴ�.
	//scanf�����ΰ� �ؼ� cin ���� �ٲ㼭 �ߴµ� �� �ȵȴ�...


	sort(persons.begin(), persons.end(), vectorcmp);

	for (int i = 0; i < N; i++) {
		cout << persons[i].age << " " <<persons[i].name << "\n";
		//printf("%d %s \n", persons[i].age, persons[i].name.c_str());
		//printf ���� %s �� ���ְ� �Ǹ� string ���¸� char* ���ڿ� ���·� �ٲ��־�� ����� �ȴ�.
		//cout�� ���� �׳� ���൵ �Ǵµ� printf�� �ٲ��ִ� .c_str()�� ���־�� �Ѵ�.
		//but ������ �𸣰����� �� ��쿡 ���ڰ� ©����..�׷��� �׳� cin�� cout���� ���ֱ�� �Ѵ�.

	}
	
	return 0;
}

