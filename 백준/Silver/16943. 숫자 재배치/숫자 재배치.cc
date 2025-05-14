#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	int a, b;

	cin >> a >> b;

	string s = to_string(a);
	vector<char> v(s.length());

	for (int i = 0; i < s.length(); i++)
		v[i] = s[i];

	sort(v.begin(), v.end());
	
	int ans = 0;
	do {
		int num = 0;
		
		for (auto& i : v){
			num *= 10;
			num += (i-'0');
		}
		if (num >= b)
			break;
		ans = num;
	} while (next_permutation(v.begin(), v.end()));

	string s2 = to_string(ans);

	if (ans == 0 ||  s.length() != s2.length())
		cout << -1;
	else
		cout << ans;
	return 0;
}
