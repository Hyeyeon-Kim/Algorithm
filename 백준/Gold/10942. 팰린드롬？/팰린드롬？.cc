#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL); 
    cout.tie(NULL); 
    
    int n;
    cin >> n;

    vector <int> input(n);
    bool dp[2001][2001] = {false};

    for (int i = 0; i < n; i++)
        cin >> input[i];

    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    for (int i = 0; i < n-1; i++)
        dp[i][i+1] = (input[i] == input[i+1]);

    for (int len = 3; len <= n; len++){
        for (int i = 0; i <= n - len; i++){
            int j = i + len-1;
            
            if ((input[i] == input[j]) && dp[i+1][j-1])
                dp[i][j] = true;
        }
    }
    int m;

    cin >> m;

    for (int i =0 ; i < m; i++){
        int a, b;
        cin >> a >> b;

        cout << dp[--a][--b] << '\n';
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++)
    //         cout << dp[i][j];
    //     cout << endl;
    // }

}




