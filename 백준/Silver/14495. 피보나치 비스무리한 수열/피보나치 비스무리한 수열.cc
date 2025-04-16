#include <iostream>
using namespace std;

long long dp[120] = {0};

long long fifo(int n){
	if (dp[n] != 0)
		return dp[n];
	if (n <= 3)
		return 1;
	
	return dp[n] = fifo(n-1) + fifo(n-3);
}

int main() {
	int n;

	cin >> n;
	cout << fifo(n);

	return 0;
}