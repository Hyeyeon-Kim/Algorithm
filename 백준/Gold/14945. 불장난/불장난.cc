#include <iostream>
using namespace std;

int main() {
	int dp[101][101] = {0};

	int n;

	cin >> n;

	dp[2][1] = 2;

	for (int i = 3;i <= n; i++){
		for (int j = 1; j < n; j++){
			dp[i][j] = 2*dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1];
			dp[i][j] %= 10007;
		}
	}

	int sum = 0;

	for (int i = 1; i < n; i++){
		sum += dp[n][i];
		sum %= 10007;
	}

	cout << sum;
}