#include <iostream>
using namespace std;

int main(){
    int t;

    int dp[100];

    dp[0] = 0;

    for (int  i = 1; i < 100; i++)
        dp[i] = dp[i-1] + i;  

    // for (int  i = 1; i < 45; i++)
    //     cout << dp[i] << " ";
    
    cin >> t;

    while (t--){
        int n;
        bool ans = false;
        cin >> n;

        for (int i = 1; i < 45 && !ans; i++){
            for (int j = 1; j < 45 && !ans; j++){
                for (int k = 1; k <45; k++){
                    if (n == (dp[i] + dp[j]+ dp[k])){
                        ans = true;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}