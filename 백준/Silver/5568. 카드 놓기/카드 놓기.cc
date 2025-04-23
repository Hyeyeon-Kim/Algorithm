#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, k;

int main() {
	cin >> n >> k;
	v.resize(n);

	for (int i = 0; i < n; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	set <string> s;

	do {
		string res;
		for (int i = 0; i < k; i++) {
			res += to_string(v[i]);
		}
		s.insert(res);
	} while (next_permutation(v.begin(), v.end()));
	
	cout << s.size();
	
	return 0;
}