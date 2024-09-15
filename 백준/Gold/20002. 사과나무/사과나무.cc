#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int tmp[301][301] = {0};
	int dp[301][301] = {0};

	cin >> n ;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> tmp[i][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + tmp[i][j];
		}
	}

	int k = 3;
	int ans = -1000;
	for (int k = 1; k < n; k++)
	{
		for (int i = k; i <= n; i++)
		{
			for (int j = k; j <= n; j++)
			{
				ans = max(ans, dp[i][j] - dp[i][j-k] - dp[i-k][j] + dp[i-k][j-k]);
				// cout << dp[i][j] - dp[i][j-k] - dp[i-k][j] + dp[i-k][j-k]<< " ";
			}
			// cout << endl;
		}
	}

	if (n == 1)
		ans = dp[1][1];

	cout << ans;
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }


}
