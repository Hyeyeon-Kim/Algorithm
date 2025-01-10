#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define MOD 1000000009
using namespace std;

bool com(array<int, 3>& a, array<int, 3>& b){
	if (a[0] != b[0])
		return (a[0] < b[0]);
	return a[1] < b[1];
}

int main()
{
	int n, d;
	int dp[10001] = {0};
	cin >> n >> d;
	vector<array<int, 3>> arr(n);

	for (int i = 1; i <= 10000; i++)
		dp[i] = i;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	sort(arr.begin(), arr.end(), com);

	for (int i = 0; i < n; i++){
		int s = arr[i][0], e = arr[i][1], c = arr[i][2];

		for (int j = e; j <= 10000; j++)
			dp[j] = min(dp[j], dp[s] + c++);
	}

	cout << dp[d];
}