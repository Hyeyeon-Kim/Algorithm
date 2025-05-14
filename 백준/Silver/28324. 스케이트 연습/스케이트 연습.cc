#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;

	cin >> n;

	vector<long long> v(n);
	vector<long long> v2(n);

	for (int i = 0; i < n; i++)	
		cin >> v[i];
	
	v2[n-1] = 1;

	for (int i = n - 2; i >= 0; i--){
		v2[i] = min(v[i], v2[i + 1] + 1);
	}

	long long ans = 0;
	for (int i = 0; i < n ; i++)
		ans += v2[i];

	cout << ans;
	return 0;
}
