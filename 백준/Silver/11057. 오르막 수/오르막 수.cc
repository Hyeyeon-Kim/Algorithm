#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define MOD 10007
using namespace std;
	
int main()
{
	int n;

	cin >> n;

	long long dp[1001][10] = {0};

	for (int i =0; i < 10; i++)
		dp[1][i] = 1;
	
	for (int i = 2; i <= n; i++){
		for (int j = 0; j < 10; j++){
			long long sum_ = 0;
			for (int k = 0; k <= j; k++)
				sum_ = (sum_ + dp[i-1][k]) % MOD;
			dp[i][j] = sum_ % MOD; 
		}
	}

	long long ans = 0;
	for (int j = 0; j < 10; j++)
		ans = (ans + dp[n][j]) % MOD; 
	cout << ans;
}