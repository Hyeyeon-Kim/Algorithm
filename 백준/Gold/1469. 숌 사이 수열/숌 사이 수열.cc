#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[8];
int ans[25]; // 결과 배열
bool use[25]; // 숫자 사용 여부

void dfs(int depth) {
    if (depth == n * 2) {
        for (int i = 0; i < n * 2; i++) {
            cout << ans[i] << " ";
        }
        exit(0);
    }

    if (ans[depth] != -1) {
        dfs(depth + 1);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!use[i] && depth + arr[i] + 1 < n * 2 && ans[depth + arr[i] + 1] == -1) {
            use[i] = true;
            ans[depth] = ans[depth + arr[i] + 1] = arr[i];

            dfs(depth + 1);

            use[i] = false;
            ans[depth] = ans[depth + arr[i] + 1] = -1;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    memset(ans, -1, sizeof(ans));
    memset(use, false, sizeof(use));

    dfs(0);
    cout << -1;
    return 0;
}
