#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define MOD 1000000009
using namespace std;
	
int main()
{
	int t;

	cin >> t;

	while(t--)
	{
		int n;
		long long dp[100001][4] = {0};
		cin >> n;

		dp[1][1] = 1;
		dp[2][2] = 1;
		dp[3][1] = 1;
		dp[3][2] = 1;
		dp[3][3] = 1;
		
		for (int i = 4; i <= n; i++){
			dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
			dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
			dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
		}

		long long ans = 0;

		for (int j = 1; j <= 3; j++){
			ans = (ans + dp[n][j]) % MOD;
		}

		cout << ans << endl;
	}
}