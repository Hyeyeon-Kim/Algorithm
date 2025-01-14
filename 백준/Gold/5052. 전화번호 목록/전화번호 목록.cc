#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct TrieNode{
	bool finish;      //단어의 끝임을 표시하는 변수
	TrieNode *child[26];  //알파벳 26개의 자식 노드 포인터

	TrieNode(): finish(false){  // 멤버 초기화 리스트 문법 (finish를 false로 초기화) 
		memset(child, 0, sizeof(child)); //모든 자식 노드 포인터를 nullptr로 설정
	}

	~TrieNode(){
		for (int i = 0 ; i < 26; i++)
			if (child[i])  // child[i]가 존재하면 삭제
				delete child[i]; 
	}

};

class Trie{
	private:
		TrieNode *root;

		int char_to_index(char c){
			return c-'0';
		}
	
	public:

		Trie(){
			root = new TrieNode();
		}

		//트라이에 문자열 삽입
		void insert(const string& word){
			TrieNode * current = root;
			
			for (char c : word){
				int idx = char_to_index(c);

				if (!current->child[idx])
					current->child[idx] = new TrieNode();

				current = current->child[idx];
			}
			current->finish = true;
		}

		// // 문자열 검색 
		// bool search(const string &word){
		// 	TrieNode *current = root;

		// 	for (char c : word){
		// 		int idx = char_to_index(c);

		// 		if (!current->child[idx])
		// 			return false;  // 경로가 끊어지면 단어가 존재하지 않음
		// 		current = current->child[idx];
		// 	}
		// 	return current->finish; //단어가 존재하는지 확인
		// }

		// bool startWith(const string &prefix){
		// 	TrieNode *current = root;

		// 	for (char c : prefix){
		// 		int idx = char_to_index(c);

		// 		if (!current->child[idx])
		// 			return false;
		// 		current = current->child[idx];
		// 	}
		// 	return true;
		// }		

		bool isNotPrefix(const string &pre){
			TrieNode *current = root;

			for (char c : pre){
				int idx = char_to_index(c);

				if (!current->child[idx])
					return true;
				
				current = current->child[idx];

				if (current->finish)
					return false;
			}
			return false; //경로가 이어졌을 경우 접두사가 존재
		}
};

int main(){

	int t;
	cin >> t;

	while(t--){
		int n;

		cin >> n;

		Trie trie;
		bool ans = true;
		
		vector<string> arr(n);

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		for (int i = 0; i < n; i++){
			if (trie.isNotPrefix(arr[i]) == false){
				ans = false;
				break;
			}
			trie.insert(arr[i]);
		}
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}