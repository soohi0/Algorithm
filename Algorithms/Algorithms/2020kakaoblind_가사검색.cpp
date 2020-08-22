#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
//���ڼ����� �¾ƾ���
//�ش��ϴ°Ÿ� ����
struct Trie {
	Trie* next[26];
	int count;
	bool isend;
	
	Trie() : isend(false), count(1) {
		memset(next, 0, sizeof(next));
	}
	~Trie()
	{
		for (int i = 0; i < 10; i++) {
			if (next[i]) delete next[i];
		}
	}
	void insert(const char* key) {
		if (*key == '\0') isend = true;
		else {
			int curr = *key - 'a';//����ġ
			if (next[curr] == NULL)
				next[curr] = new Trie();
			else next[curr]->count++;
			next[curr]->insert(key + 1);
		}
	}
	int find(const char* key)
	{
		int curr = *key - 'a';
		if (*key == '?') {
			int tmp = 0;
			for (int k = 0; k < 26; k++)
			{
				if (next[k] != NULL)
					tmp += next[k]->count;
			}return tmp;
		}
		if (next[curr] == NULL) return 0;
		if (*(key + 1) == '?') return next[curr]->count;
		return next[curr]->find(key + 1);
	}
};
vector<string> rightwordNum(char q, vector<string>chk, int j)
{
	//���ڰ� �´ٸ� �Ѿ�µ�
	//Ʋ���� �ٷ� ���� word�� �Ѿ���� �� ������ �����..
	vector<string> chks;
	for (int k = 0; k < chk.size(); k++)
	{
		if (chk[k][j] == q) {
			chks.push_back(chk[k]);
		}
	}
	return chks;
}
Trie *root[10001];
Trie *reroot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
	//=======================d�� ������� �ϸ� �ð��ʰ� -> TRIe �����
	/*vector<int> answer(queries.size());
	//q���ʴ�� �˻�.
	//word �� sort ��Ų��.
	
	//���ڼ����� �Ÿ���
	for (int i = 0; i < queries.size(); i++)
	{
		vector<string> chkv;
		//���ڼ� �´°� �Ÿ� v
		int strlength = queries[i].length();
		bool isfront = true;
		if (queries[i][0] == '?') isfront = false;
		else isfront = true;
		
		for (int j = 0; j < words.size(); j++)
		{
			if (words[j].length() == strlength)
			{
				chkv.push_back(words[j]);
			}
		}
		if (isfront)
		{

				for (int j = 0; queries[i][j] != '?'; j++)
				{
					//pair<string, int> p;
					if (queries[i][j] != '?')//������ �� ��.
					{
						chkv = rightwordNum(queries[i][j], chkv, j);
					}
				}//?���� ���� ��� üũ���� �� true�� �߰�.
				answer[i] = chkv.size();
			
		}
		else {
            if (queries[i][strlength - 1] == '?') {
				//?�ۿ� ���� ���
				answer[i] = chkv.size();
			}
            else{
                for (int j = strlength -1; queries[i][j] != '?'; j--)
			    {
				//pair<string, int> p;
                    if (queries[i][j] != '?')//������ �� ��.
				    {
					    chkv = rightwordNum(queries[i][j], chkv, j);
				    }
			    }//?���� ���� ��� üũ���� �� true�� �߰�.
			    answer[i] = chkv.size();
            }
			

		}
		
	}

	return answer;*/
	int wsize = words.size();
	int qsize = queries.size();
	vector<int> answer(qsize, 0);


	for (auto &a : words) {
		int size = a.size();

		const char *c = a.c_str();
		if (root[size] == NULL) root[size] = new Trie();
		root[size]->insert(c);


		string reversed_string = a;
		reverse(reversed_string.begin(), reversed_string.end());

		const char *k = reversed_string.c_str();
		if (reroot[size] == NULL) reroot[size] = new Trie();
		reroot[size]->insert(k);

	}

	int idx = 0;

	for (auto &a : queries) {

		int size = a.size();

		if (a[size - 1] == '?') {
			const char *c = a.c_str();

			if (root[size] == NULL) { idx++; continue; }
			else answer[idx] = root[size]->find(c);

		}
		else {
			string re = a;
			reverse(re.begin(), re.end());
			const char *k = re.c_str();

			if (reroot[size] == NULL) { idx++; continue; }
			else answer[idx] = reroot[size]->find(k);
		}
		idx++;
	}

	return answer;

}

int main()
{
	vector<string> word;
	word.push_back("frodo");
	word.push_back("front");
	word.push_back("frost");
	word.push_back("frozen");
	word.push_back("frame");
	word.push_back("kakao");

	vector<string> queries;
	queries.push_back("fro??");
	queries.push_back("????o");
	queries.push_back("fr???");
	queries.push_back("fro???");
	queries.push_back("pro?");
	queries.push_back("?????");
	vector <int> ans = solution(word, queries);

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}