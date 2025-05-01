#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double n, l, w, h;
    cin >> n >> l >> w >> h;

    double s = 0; 
    double e = min({l, w, h});
    double ans = 0;

    for (int cnt = 0; cnt < 100; cnt++) { 
        double mid = (s + e) / 2; 
        long long int a = floor(l / mid) * floor(w / mid) * floor(h / mid);

        if (n <= a) {
            ans = mid; 
            s = mid;
        } else {
            e = mid;  
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << ans << '\n';

    return 0;
}