#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;

ll n, p, q, x, y;
unordered_map<ll, ll> dp;

ll f(ll n) {
    if(n <= 0) 
		return 1;

    if(dp.find(n) != dp.end()) 
		return dp[n];
    
    ll result = f(n / p - x) + f(n / q - y);
    dp[n] = result;
    return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> p >> q >> x >> y;
	cout << f(n) << "\n";
	return 0;
}