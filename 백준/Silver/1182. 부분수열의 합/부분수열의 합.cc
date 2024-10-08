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
        if (sum == s && cnt > 0)
            ans++;
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
    dfs(0, 0, 0);
    cout << ans ;
}   
