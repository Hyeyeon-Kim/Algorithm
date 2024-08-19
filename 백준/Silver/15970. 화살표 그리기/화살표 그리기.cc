#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INT_MAX 2147483647

using namespace std;

bool com(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> sorted(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        sorted[i] = {b, a}; // {color, position}
    }

    sort(sorted.begin(), sorted.end()); // 색상으로 정렬, 색상이 같으면 위치로 정렬됨

    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        int pos = sorted[i].second;
        int color = sorted[i].first;
        
        int dist_left = INT_MAX;
        int dist_right = INT_MAX;

        // 왼쪽 거리
        if (i > 0 && sorted[i - 1].first == color) {
            dist_left = pos - sorted[i - 1].second;
        }

        // 오른쪽 거리
        if (i < n - 1 && sorted[i + 1].first == color) {
            dist_right = sorted[i + 1].second - pos;
        }

        ans += min(dist_left, dist_right);
    }

    cout << ans << endl;

    return 0;
}
