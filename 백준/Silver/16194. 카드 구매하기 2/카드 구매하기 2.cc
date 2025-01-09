#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define MOD 9901
using namespace std;
	
int main()
{
	int n;
	long long dp[1001] = {0};
	int arr[1000];

	cin >> n;

	for (int i = 1 ;i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];

	for (int i = 2; i <= n; i++){ // <= 장 수 
		dp[i] = arr[i];

		for (int j = 1; j <= i; j++) // <= 카드 팩 종류 
			dp[i] = min(dp[i], dp[i- j] + arr[j]);
	}

	cout << dp[n];
}