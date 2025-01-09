#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define MOD 1000000000
using namespace std;
	
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;

		cin >> n;

		int dp[3][100001] = {0};
		int arr[3][100001];

		for (int i = 1; i <= 2; i++){
			for (int j = 1; j <= n; j++)
				cin >> arr[i][j];
		}

		dp[1][1] = arr[1][1];
		dp[2][1] = arr[2][1];

		for (int i = 2; i <= n; i++){
			dp[1][i] = max(max(dp[2][i-1], dp[2][i-2]), dp[1][i-2]); 
			dp[1][i] += arr[1][i];

			dp[2][i] = max(max(dp[1][i-1], dp[1][i-2]), dp[2][i-2]); 
			dp[2][i] += arr[2][i];
		} 


		cout << max(dp[1][n], dp[2][n]) << endl;
	}
}