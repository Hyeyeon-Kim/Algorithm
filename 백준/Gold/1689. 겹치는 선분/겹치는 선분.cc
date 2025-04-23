#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	
	cin >> n;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++){
		int a, b;
		
		cin >> a >> b;
		v.push_back({a, 1});
		v.push_back({b, -1});
	}
	
	sort(v.begin(), v.end());
	
	int i = 0;
	int max_ = 0;
	int cnt = 0;

	for (int i = 0; i < v.size(); i++){
		cnt += v[i].second;
		max_ = max(max_, cnt);
	}

	cout << max_ << endl;
	return 0;
}