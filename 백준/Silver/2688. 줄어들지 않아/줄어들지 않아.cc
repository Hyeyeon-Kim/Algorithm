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

	while (t--)
	{
		int n;
		cin >> n;

		long long dp[65][10] = {0};

		for (int i = 0 ; i < 10; i++)
			dp[1][i] = 1;
		

		for (int i = 2; i <= n; i++){
			for (int j = 0; j < 10; j++){
				long long sum_ = 0;
				for (int k = 0; k <= j; k++)
					sum_ += dp[i-1][k];
				dp[i][j] = sum_;
			}
		}

		long long ans = 0;
		
		for (int i = 0 ; i < 10; i++)
			ans += dp[n][i];	
		cout << ans << endl;
	}
}