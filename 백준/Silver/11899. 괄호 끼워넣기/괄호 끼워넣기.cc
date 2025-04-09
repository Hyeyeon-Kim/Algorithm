#include <iostream>
#include <stack>
using namespace std;

int main() {
	string s;

	cin >> s;

	stack <int> st;
	int cnt = 0;
	
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '('){
			st.push(1);
		}
		else{
			if (!st.empty()){
				st.pop();
			}
			else
				cnt++;
		}
	}

	cnt += st.size();

	cout << cnt;
	
	return 0;
}