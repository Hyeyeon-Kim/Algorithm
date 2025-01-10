#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define MOD 1000000009
using namespace std;
	
int main()
{
	int n, s, m;
	int v[51];
	bool dp[51][1001] = {0};

	cin >> n >> s >> m;

	for (int i = 1; i <= n; i++)
		cin >> v[i];
	
	dp[0][s] = true;

	for (int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if (j + v[i] <= m && dp[i-1][j] == true)
				dp[i][j+v[i]] = true;
			if (j - v[i] >= 0 && dp[i-1][j] == true)
				dp[i][j-v[i]] = true;
		}
	}

	int ans = -1;

	for (int i = 0; i <= m; i++){
		if (dp[n][i])
			ans = i;
	}

	cout << ans;
}