#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	long long arr[1025][1025];
	long long dp[1025][1025] = { 0 };

	cin >> n >> m;

	for (int i = 1; i <= n;i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i-1][j-1];
		}
	}


	while (m--)
	{
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << '\n';
	}

	
}