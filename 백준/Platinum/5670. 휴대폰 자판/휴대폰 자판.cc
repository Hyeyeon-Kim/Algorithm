#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct TrieNode{
	bool finish;      //단어의 끝임을 표시하는 변수
	// TrieNode *child[26];  //알파벳 26개의 자식 노드 포인터
	map<char, TrieNode *> child;

	TrieNode(): finish(false){  // 멤버 초기화 리스트 문법 (finish를 false로 초기화) 
		// memset(child, 0, sizeof(child)); //모든 자식 노드 포인터를 nullptr로 설정
	}
};

class Trie{
	public:
		TrieNode *root;

		Trie(){
			root = new TrieNode();
		}

		//트라이에 문자열 삽입
		void insert(const string &word){
			TrieNode * current = root;
			
			for (char c : word){
				if (current->child.find(c) == current->child.end())
					current->child[c] = new TrieNode;

				current = current->child[c];
			}
			current->finish = true;
		}

		int putBotton(const string &word){
			TrieNode *current = root;

			int cnt = 1;

			current = current->child[word[0]];

			for (int i = 1; i < (int)word.size(); i++){
				// cout << current->child.size() << endl;
				if (current->child.size() > 1 || current->finish == true)
					cnt++;

				current = current->child[word[i]];
			}
			return cnt;
		}
};

int main(){
	int n;

	while (cin >> n){
		Trie trie;

		vector<string> s(n);

		for (int i = 0; i < n; i++){
			cin >> s[i];
			trie.insert(s[i]);
		}

		float sum = 0;

		for (int i = 0; i < n; i++){
			sum += trie.putBotton(s[i]);
		}

		printf("%.2lf\n", (sum/n));
	}
}