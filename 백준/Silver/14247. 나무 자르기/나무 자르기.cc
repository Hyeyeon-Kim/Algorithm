#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;

    cin >> n;
    vector <pair<long long,long long>> grow(n);
    vector <long long> tree(n);

    for (long long i = 0; i < n; i++)
        cin >> tree[i];
    for (long long i = 0; i < n; i++){
        cin >> grow[i].first;
        grow[i].second = i;
    }

    sort(grow.begin(), grow.end());

    long long ans = 0;
    for (long long i = 0; i < n; i++){
        // cout << grow[i].first << " " << grow[i].second << endl;
        ans += grow[i].first * i + tree[grow[i].second];
    }

    cout << ans;

}

