#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getPos(int d, int p, int w, int h) {
    if (d == 1) return p;
    if (d == 2) return 2 * w + h - p;
    if (d == 3) return 2 * (w + h) - p;
    return w + p; // d == 4
}

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    vector<int> shop(n);
    for (int i = 0; i < n; ++i) {
        int d, p;
        cin >> d >> p;
        shop[i] = getPos(d, p, w, h);
    }

    int gd, gp;
    cin >> gd >> gp;
    int gpos = getPos(gd, gp, w, h);
    int len = 2 * (w + h), sum = 0;

    for (int s : shop) {
        int dist = abs(gpos - s);
        sum += min(dist, len - dist);
    }

    cout << sum << '\n';
}
