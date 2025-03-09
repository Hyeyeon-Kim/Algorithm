#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int t = 0; t < 3; t++){
		int n;

        cin >> n;
        
        vector<pair<int, int>> coins;
        int total = 0;

        for (int i = 0; i < n; i++){
            int value, count;

            cin >> value >> count;
            coins.push_back({value, count});
            total += value * count;
        }
        
        if (total % 2 != 0) {
            cout << 0 << "\n";
            continue;
        }
        
        int half = total / 2;

        vector<int> dp(half + 1, -1);
        dp[0] = 0;
        
        for (auto &coin : coins) {
            int value = coin.first, count = coin.second;
            for (int j = 0; j <= half; j++){
                if (dp[j] >= 0) 
                    dp[j] = count;
                 else if (j < value || dp[j - value] <= 0) 
                    dp[j] = -1;
                else 
                    dp[j] = dp[j - value] - 1;
                
            }
        }
        
        cout << (dp[half] >= 0 ? 1 : 0) << "\n";
    }
}   
