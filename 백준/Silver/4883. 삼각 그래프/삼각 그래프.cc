#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define MOD 1000000009
using namespace std;

int main()
{
	int n;
	int t = 1;
	while (1)
	{
		cin >> n;

		if (n == 0)
			break;
		long long arr[100001][4];
		long long dp[100001][4] = {0};
		

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> arr[i][j];
		
		dp[1][1] = 987654321;
		dp[1][2] = arr[1][2];
		dp[1][3] = arr[1][2] + arr[1][3];

		for (int i = 2; i <= n; i++){
			dp[i][1] = min(dp[i-1][1], dp[i-1][2]) + arr[i][1];

			dp[i][2] = min(dp[i-1][1], min(dp[i][1], min(dp[i-1][2], dp[i-1][3]))) + arr[i][2];

			dp[i][3] = min(dp[i][2], min(dp[i-1][2], dp[i-1][3])) + arr[i][3];
		}

		cout << t << ". " << dp[n][2] << endl;
		t++;
	}
}