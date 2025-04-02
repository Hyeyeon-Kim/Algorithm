#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k, b;

	cin >> n >> k >> b;
	vector<int> blinker(n+1);

	for (int i = 0; i < b; i++){
		int idx;
		cin >> idx;
		blinker[idx] = 1;
	}

	int s = 1;
	int e = k;
	int sum = 0;

	for (int i = 1; i <= k; i++)
		sum += blinker[i];
	
	int min_ = sum;
	while (e < n){
		e++;
		sum += blinker[e];
		sum -= blinker[s];
		s++;
		min_= min(min_, sum);
	}

	cout << min_;
	return 0;
}
// 10^5
// *1 *2 3 4 *5 6 7 8 *9 *10