#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<pair<int, int>> coor;

int manhattan(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    cin >> n;
    coor.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> coor[i].first >> coor[i].second;
    }

    int total = 0;
    for (int i = 1; i < n; i++) {
        total += manhattan(coor[i - 1], coor[i]);
    }

    int max_diff = 0;
    for (int i = 1; i < n - 1; i++) {
        int without_i = manhattan(coor[i - 1], coor[i]) + manhattan(coor[i], coor[i + 1]);
        int skip_i = manhattan(coor[i - 1], coor[i + 1]);
        max_diff = max(max_diff, without_i - skip_i);
    }

    cout << total - max_diff << endl;

    return 0;
}
