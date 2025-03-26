#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> b;

int main() {
	
	int na, nb;

	cin >> na >> nb;
	a.resize(na);
	b.resize(nb);

	for (int i = 0; i < na; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	for (int i = 0; i < nb; i++)
		cin >> b[i];
	
	sort(b.begin(), b.end());

	vector<int> ans;

	for (int i = 0; i < na; i++){
		int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

		// cout <<idx<< " " << b[idx]<< endl;
		if (b[idx] != a[i])
			ans.push_back(a[i]);
	}	
	cout << ans.size() << endl;
	for (int tmp : ans)
	cout << tmp << ' ';
	return 0;
}