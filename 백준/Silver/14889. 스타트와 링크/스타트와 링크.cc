#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[21][21];

int use[21] = {0};
vector<int> a;
long long ans = 987654321;

void dfs(int pre, int cnt){

    if (cnt == n/2){
        long a_sum = 0;
        long b_sum = 0;

        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (use[i] && use[j])
                    a_sum += map[i][j] + map[j][i];
                else if (!use[i] && !use[j])
                    b_sum += map[i][j] + map[j][i];
            }
            // cout << endl;
        }

        ans = min(ans, (long long)abs(a_sum - b_sum));
        return;
    }

    for (int i = pre; i < n; i++){
        if (use[i] == 0){
            a[cnt] = i;
            use[i] = 1;
            dfs(i + 1, cnt + 1);
            use[i] = 0;
        }
    }
}

int main(){

    cin >> n;
    a.resize(n/2);

    for (int i = 0; i <n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    
    dfs(0, 0);

    cout << ans;
}