#include <iostream>
#include <vector>
using namespace std;

int dp[51] = {0};
int ans = 0;

int fibo(int n){
	ans++;
	if (n < 2)
		return dp[n];
	
	if (dp[n] != 0)
		return dp[n];
	
	return dp[n] = (fibo(n-2) % 1000000007 + fibo(n-1) % 1000000007 + 1) % 1000000007;
	// if (n < 2) {
	// 	return n;
	// }  
	// return fibo(n-2) + fibo(n-1);
}

int main(){
    int n; 
    
    cin >> n;
    
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;

	cout << fibo(n);

	// cout << ans;
}

//269253
