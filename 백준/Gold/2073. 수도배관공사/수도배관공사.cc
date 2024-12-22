#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int D, P;
	int L[351] = {0}, C[351] = {0};
	cin >> D >> P;

	int dp[100001] = {0};

	for (int i = 1; i <= P; i++)
		cin >> L[i] >> C[i];

	dp[0] = INT32_MAX;
	
	for (int i = 1; i <= P; i++){
		for (int j = D; j >= L[i]; j--){
			dp[j] = max(min(dp[j-L[i]], C[i]), dp[j]); 
		}
	}

	cout << dp[D] << endl;
}