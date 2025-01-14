#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct TrieNode{
	bool finish;      //단어의 끝임을 표시하는 변수
	// TrieNode *child[26];  //알파벳 26개의 자식 노드 포인터
	map<string, TrieNode *> child;

	TrieNode(): finish(false){  // 멤버 초기화 리스트 문법 (finish를 false로 초기화) 
		// memset(child, 0, sizeof(child)); //모든 자식 노드 포인터를 nullptr로 설정
	}

	// ~TrieNode(){
	// 	for (int i = 0 ; i < 26; i++)
	// 		if (child[i])  // child[i]가 존재하면 삭제
	// 			delete child[i]; 
	// }

};

class Trie{
	public:
		TrieNode *root;

		Trie(){
			root = new TrieNode();
		}

		//트라이에 문자열 삽입
		void insert(const vector<string>& arr){
			TrieNode * current = root;
			
			for (string word : arr){
				if (current->child.find(word) == current->child.end())
					current->child[word] = new TrieNode;

				current = current->child[word];
			}
			current->finish = true;
		}
};

void print(int deep, TrieNode *current){
	if (current->finish)
		return ;

	for (auto iter = current->child.begin(); iter != current->child.end(); iter++){
		for (int i = 0; i < deep; i++)
			cout << "--";
		cout << iter->first << endl;

		print(deep+1, iter->second);
	}
}

int main(){
	int n;

	cin >> n;

	Trie trie;

	for (int i = 0; i < n; i++){
		int k;

		cin >> k;
		vector <string> input(k);

		for (int j = 0; j < k; j++)
			cin >> input[j];

		trie.insert(input);
	}

	print(0, trie.root);
}