#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
int arr[21] = {0};
int ans = 0;
int tmp[21] = {0};

void dfs(int idx, int sum, int cnt){
    if (idx == n){
        if (sum == s && cnt > 0){
            // cout << sum << ": ";
            // for (int i = 0; i < cnt; i++)
            //     cout << tmp[i] << " ";
            // cout << endl;
            ans++;
        }
        return ;
    }

    tmp[cnt] = arr[idx];
    dfs(idx+1, sum + arr[idx], cnt+1);
    dfs(idx+1, sum, cnt);
}

int main() {
    cin >> n >> s;

    for (int i =0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    // for (int i = 0; i < n; i++)
    //     cout <<arr[i] << " ";
    // cout << endl;
    dfs(0, 0, 0);
    cout << ans ;
}   
